-- ============================================
-- Database Assignment 1 Solution
-- ============================================

-- Create Database
CREATE DATABASE IF NOT EXISTS LibraryDB;
USE LibraryDB;

-- ============================================
-- Question 1 and 2
-- Create Student, Library and Fees tables
-- with proper relationships
-- Add proper constraints with the No 1 question
-- ============================================

CREATE TABLE Student (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    Phone VARCHAR(20) UNIQUE,
    Department VARCHAR(50),
    AdmissionDate DATE DEFAULT (CURRENT_DATE)
);

CREATE TABLE Library (
    LibraryID INT PRIMARY KEY AUTO_INCREMENT,
    StudentID INT NOT NULL,
    BookName VARCHAR(100) NOT NULL,
    IssueDate DATE NOT NULL,
    ReturnDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);

CREATE TABLE Fees (
    FeeID INT PRIMARY KEY AUTO_INCREMENT,
    StudentID INT NOT NULL,
    Amount DECIMAL(10,2) NOT NULL CHECK (Amount >= 0),
    PaymentDate DATE,
    Status VARCHAR(20) DEFAULT 'Unpaid',
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
);

-- ============================================
-- Sample Data
-- ============================================

INSERT INTO Student
(FirstName, LastName, Email, Phone, Department)
VALUES
('John','Doe','john@gmail.com','01711111111','CSE'),
('Jane','Smith','jane@gmail.com','01722222222','EEE'),
('Michael','Johnson','michael@gmail.com','01733333333','BBA');

INSERT INTO Library
(StudentID, BookName, IssueDate, ReturnDate)
VALUES
(1,'Database Systems','2026-08-01','2026-08-15'),
(2,'Operating System','2026-08-02','2026-08-16'),
(3,'Computer Networks','2026-08-03','2026-08-17');

INSERT INTO Fees
(StudentID, Amount, PaymentDate, Status)
VALUES
(1,5000,'2026-08-01','Paid'),
(2,5000,NULL,'Unpaid'),
(3,5000,'2026-08-03','Paid');

-- ============================================
-- Question 3
-- Difference Between Data and Information
-- ============================================

/*

DATA
1. Raw facts.
2. Unprocessed.
3. No meaningful context.
4. Used as input.
5. Example: 85, John, CSE.

INFORMATION
1. Processed data.
2. Meaningful.
3. Helps decision making.
4. Output after processing.
5. Example: John scored 85 marks.

*/

-- ============================================
-- Question 4
-- Why UPDATE and DELETE were not executing?
-- ============================================

/*

Reason:
MySQL Safe Update Mode was enabled.

Disable Safe Update Mode

*/

SET SQL_SAFE_UPDATES = 0;

-- Example

UPDATE Student
SET Department='CS'
WHERE StudentID=1;

DELETE FROM Student
WHERE StudentID=3;

-- ============================================
-- Employee Table
-- ============================================

DROP TABLE IF EXISTS Employee;

CREATE TABLE Employee(
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Age INT,
    Department VARCHAR(50)
);

INSERT INTO Employee VALUES
(1,'John','Doe',28,'Sales'),
(2,'Jane','Smith',32,'Marketing'),
(3,'Michael','Johnson',35,'Finance'),
(4,'Sarah','Brown',30,'HR'),
(5,'William','Davis',25,'Engineering'),
(6,'Emily','Wilson',28,'Sales'),
(7,'Robert','Lee',33,'Marketing'),
(8,'Laura','Hall',29,'Finance'),
(9,'Thomas','White',31,'HR'),
(10,'Olivia','Clark',27,'Engineering');

-- ============================================
-- Question 5
-- Distinct Department Names
-- ============================================

SELECT DISTINCT Department
FROM Employee;

-- ============================================
-- Question 6
-- LastName sorted by descending Age
-- ============================================

SELECT LastName
FROM Employee
ORDER BY Age DESC;

-- ============================================
-- Question 7
-- LastName where Age > 30
-- and Department = Marketing
-- ============================================

SELECT LastName
FROM Employee
WHERE Age > 30
AND Department='Marketing';

-- ============================================
-- Question 8
-- Select all employees
-- ============================================

SELECT *
FROM Employee;

-- ============================================
-- Question 9
-- Employee names containing 'son'
-- ============================================

SELECT *
FROM Employee
WHERE FirstName LIKE '%son%'
   OR LastName LIKE '%son%';

-- ============================================
-- Question 10
-- Get Engineers
-- ============================================

SELECT *
FROM Employee
WHERE Department='Engineering';

-- ============================================
-- End of Assignment
-- ============================================