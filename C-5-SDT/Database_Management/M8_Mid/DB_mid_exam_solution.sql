-- =============================================
-- Mid Term Exam
-- Question 1
-- =============================================

/*
Difference Between Primary Key and Foreign Key

Primary Key
------------
1. Uniquely identifies each record in a table.
2. Cannot contain NULL values.
3. Duplicate values are not allowed.
4. Only one Primary Key can exist in a table.
5. Maintains entity integrity.

Foreign Key
------------
1. Creates a relationship between two tables.
2. References the Primary Key of another table.
3. Can contain NULL values (unless restricted).
4. Duplicate values are allowed.
5. Maintains referential integrity.
*/

-- =============================================
-- Question 2
-- Self Join
-- =============================================

/*
A Self Join is a join in which a table is joined with itself.
It is used when rows of the same table are related to each other.

Example:
Display employees who have the same Manager_ID,
showing only their first names and manager IDs.
*/

SELECT
    e1.first_name AS Employee1,
    e2.first_name AS Employee2,
    e1.manager_id
FROM employees e1
JOIN employees e2
    ON e1.manager_id = e2.manager_id
WHERE e1.employee_id < e2.employee_id
      AND e1.manager_id IS NOT NULL;

-- =============================================
-- Question 3
-- Create Tables
-- =============================================

CREATE TABLE Employees (
    Employee_ID INT PRIMARY KEY,
    First_Name VARCHAR(50) NOT NULL,
    Last_Name VARCHAR(50) NOT NULL,
    Date_of_Birth DATE NOT NULL,
    Department_ID INT,
    Salary DECIMAL(10,2) NOT NULL
);

CREATE TABLE Projects (
    Project_ID INT PRIMARY KEY,
    Project_Name VARCHAR(100) NOT NULL,
    Start_Date DATE,
    End_Date DATE,
    Budget DECIMAL(12,2)
);

CREATE TABLE Employee_Projects (
    Employee_ID INT,
    Project_ID INT,

    PRIMARY KEY (Employee_ID, Project_ID),

    FOREIGN KEY (Employee_ID)
        REFERENCES Employees(Employee_ID)
        ON DELETE CASCADE
        ON UPDATE CASCADE,

    FOREIGN KEY (Project_ID)
        REFERENCES Projects(Project_ID)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- The Employee_Projects table implements a many-to-many relationship,
-- allowing:
-- 1. One employee to work on multiple projects.
-- 2. One project to have multiple employees.


-- =============================================
-- Mid Term Exam Solutions
-- Questions 4 - 10
-- Database: dummydb (HR Schema)
-- =============================================

USE dummydb;

-- =====================================================
-- Question 4
-- Get the Third Highest Salary
-- =====================================================

SELECT DISTINCT salary
FROM employees
ORDER BY salary DESC
LIMIT 1 OFFSET 2;

-- Alternative Solution
/*
SELECT MAX(salary) AS Third_Highest_Salary
FROM employees
WHERE salary <
(
    SELECT MAX(salary)
    FROM employees
    WHERE salary <
    (
        SELECT MAX(salary)
        FROM employees
    )
);
*/

-- =====================================================
-- Question 5
-- Department Names and Number of Employees
-- =====================================================

SELECT
    d.department_name,
    COUNT(e.employee_id) AS total_employees
FROM departments d
LEFT JOIN employees e
    ON d.department_id = e.department_id
GROUP BY d.department_id, d.department_name
ORDER BY d.department_name;

-- =====================================================
-- Question 6
-- JOIN Examples
-- =====================================================

-- INNER JOIN
SELECT
    e.first_name,
    e.last_name,
    d.department_name
FROM employees e
INNER JOIN departments d
ON e.department_id = d.department_id;


-- LEFT JOIN
SELECT
    e.first_name,
    e.last_name,
    d.department_name
FROM employees e
LEFT JOIN departments d
ON e.department_id = d.department_id;


-- RIGHT JOIN
SELECT
    e.first_name,
    e.last_name,
    d.department_name
FROM employees e
RIGHT JOIN departments d
ON e.department_id = d.department_id;


-- CROSS JOIN
SELECT
    e.first_name,
    d.department_name
FROM employees e
CROSS JOIN departments d;

-- =====================================================
-- Question 7
-- Common Table Expression (CTE)
-- =====================================================

/*
A Common Table Expression (CTE) is a temporary named result set
that exists only during the execution of a SQL statement.
It improves query readability and simplifies complex queries.
*/

WITH AverageSalary AS
(
    SELECT AVG(salary) AS avg_salary
    FROM employees
)

SELECT
    first_name,
    last_name,
    salary
FROM employees
WHERE salary >
(
    SELECT avg_salary
    FROM AverageSalary
);

-- =====================================================
-- Question 8
-- Employees earning less than Steven King
-- =====================================================

SELECT
    first_name,
    last_name,
    salary
FROM employees
WHERE salary <
(
    SELECT salary
    FROM employees
    WHERE first_name = 'Steven'
      AND last_name = 'King'
);

-- =====================================================
-- Question 9
-- Department Name and Manager Name
-- =====================================================

SELECT
    d.department_name,
    e.first_name AS manager_first_name,
    e.last_name AS manager_last_name
FROM departments d
JOIN employees e
ON d.manager_id = e.employee_id;

-- =====================================================
-- Question 10
-- Display Names of All Cities
-- Where Departments Are Located
-- =====================================================

SELECT DISTINCT
    l.city
FROM locations l
JOIN departments d
ON l.location_id = d.location_id
ORDER BY l.city;

-- Alternative (if question asks with department names)

/*
SELECT
    d.department_name,
    l.city
FROM departments d
JOIN locations l
ON d.location_id = l.location_id;
*/

-- =============================================
-- End of Solution
-- =============================================