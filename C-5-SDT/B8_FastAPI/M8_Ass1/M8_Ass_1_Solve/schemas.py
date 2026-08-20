from pydantic import BaseModel, Field
from typing import Literal, Optional

GenreType = Literal["action", "comedy", "drama", "thriller"]


class MovieCreate(BaseModel):
    movie_id: int
    title: str
    director: str
    genre: GenreType
    duration: int = Field(gt=0)
    rating: float = Field(ge=0, le=5)


class MovieUpdate(BaseModel):
    title: str
    director: str
    genre: GenreType
    duration: int = Field(gt=0)
    rating: float = Field(ge=0, le=5)
