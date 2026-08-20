from fastapi import FastAPI, Depends, HTTPException, Query
from sqlalchemy.orm import Session
from typing import Annotated, Literal
import models
from models import Movies
from schemas import MovieCreate, MovieUpdate
from database import engine, SessionLocal
from fastapi.responses import JSONResponse

app = FastAPI()

models.Base.metadata.create_all(bind=engine)


def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


db_dependency = Annotated[Session, Depends(get_db)]


@app.get('/movies')
def read_movies(db: db_dependency):
    return db.query(Movies).all()


# NOTE: /movies/sort must be declared BEFORE /movies/{movie_id}
# otherwise FastAPI will treat "sort" as a movie_id path value.
@app.get('/movies/sort')
def sort_movies(
    db: db_dependency,
    sort_by: Literal["duration", "rating"] = Query(default="rating"),
    order: Literal["asc", "desc"] = Query(default="desc"),
):
    column = Movies.duration if sort_by == "duration" else Movies.rating

    if order == "asc":
        movies = db.query(Movies).order_by(column.asc()).all()
    else:
        movies = db.query(Movies).order_by(column.desc()).all()

    return movies


@app.get('/movies/{movie_id}')
def read_specific_movie(db: db_dependency, movie_id: int):
    movie = db.query(Movies).filter(Movies.movie_id == movie_id).first()
    if movie is not None:
        return movie
    else:
        raise HTTPException(status_code=404, detail='Movie not found')


@app.post('/create_movies')
def create_movie(db: db_dependency, new_movie: MovieCreate):
    existing_movie = db.query(Movies).filter(Movies.movie_id == new_movie.movie_id).first()
    if existing_movie is not None:
        raise HTTPException(status_code=400, detail='Movie with this movie_id already exists')

    movie_model = Movies(**new_movie.model_dump())
    db.add(movie_model)
    db.commit()
    db.refresh(movie_model)

    return JSONResponse(status_code=201, content={
        'message': 'Movie created successfully',
        'movie': {
            'movie_id': movie_model.movie_id,
            'title': movie_model.title,
            'director': movie_model.director,
            'genre': movie_model.genre,
            'duration': movie_model.duration,
            'rating': movie_model.rating,
        }
    })


@app.put('/movies/{movie_id}')
def update_movie(db: db_dependency, movie_id: int, update_movie: MovieUpdate):
    movie = db.query(Movies).filter(Movies.movie_id == movie_id).first()
    if movie is None:
        raise HTTPException(status_code=404, detail='Movie not found')

    update_data = update_movie.model_dump()
    for key, value in update_data.items():
        setattr(movie, key, value)

    db.commit()
    db.refresh(movie)

    return JSONResponse(status_code=200, content={
        'message': 'Movie updated successfully',
        'movie': {
            'movie_id': movie.movie_id,
            'title': movie.title,
            'director': movie.director,
            'genre': movie.genre,
            'duration': movie.duration,
            'rating': movie.rating,
        }
    })


@app.delete('/movies/{movie_id}')
def delete_movie(db: db_dependency, movie_id: int):
    movie = db.query(Movies).filter(Movies.movie_id == movie_id).first()
    if movie is None:
        raise HTTPException(status_code=404, detail='Movie not found')

    db.query(Movies).filter(Movies.movie_id == movie_id).delete()
    db.commit()

    return JSONResponse(status_code=200, content={'message': 'Movie deleted successfully'})
