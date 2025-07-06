# ACSQL – Student Database Engine

This project implements a simplified **relational database system** in C, called **ACSQL**, designed to manage students, courses, and their enrollments. It was created as part of the third programming assignment for the _Computer Programming_ course (PCLP).

ACSQL reads data from a structured input file, allows users to perform queries and updates in a SQL-like language, and supports secure encryption of student data using a lightweight CBC-based encryption scheme.

## Features

- Read and parse database from a structured file
- Store and manage students, courses, and enrollments
- SQL-like commands:
  - `SELECT` with filters (`WHERE`, `AND`)
  - `UPDATE` with conditions
  - `DELETE` operations
- Automatic computation of general average for students
- Encrypted binary storage using:
  - XOR-based substitution (S-Box)
  - Block permutation (P-Box)
  - Cipher Block Chaining (CBC) mode

## Task Overview and Implementation

### 🗂️ Task 1: Load, Add, and Free Database

- **1.1 `citeste_secretariat()`**  
  Read the input file in two passes: the first to count records and the second to populate the dynamically allocated `secretariat` structure. Used `fseek` to reset the file pointer.

- **1.2 `adauga_student()`**  
  Implemented simple logic to reallocate the `studenti` vector and append a new student.

- **1.3 `elibereaza_secretariat()`**  
  Freed all dynamic fields (`studenti`, `materii`, `inrolari`) and set the pointer to `NULL` to avoid dangling references.

### 📋 Task 2: SQL-like Query & Modification Engine

Created helper functions to modularize logic reused across commands:

- `interogare_studenti`, `interogare_materii`, `interogare_inrolari`:  
  Handle filter logic (both simple and complex) for each table. These functions support reuse across `SELECT`, `UPDATE`, and `DELETE`.

- `afisare_studenti`, `afisare_inrolari`, `afisare_materii`:  
  Print entries matching the final filtered result using `afisari[]` and `afisari2[]` arrays for logical selection.

- `verif_sir`, `verif_int`, `verif_float`:  
  Compare fields based on type, operator, and value.

- For `SELECT`:
  - Implemented support for wildcard `*`
  - Handled multiple fields and filtering logic

- For `UPDATE`:
  - Parsed and updated fields conditionally, excluding ID fields
  - Handled special update syntax for notes

- For `DELETE`:
  - Removed matching entries using filtered result vectors

The solution is modular, and each component is validated independently before being executed.

### 🔐 Task 3: Encrypt Student Data (CBC Mode)

- Followed the encryption instructions closely:
  - Divided the student byte stream into 4 equal-sized blocks
  - Applied CBC chaining with XOR
  - Used repeated `IV` and `key` where necessary
  - Implemented:
    - S-Box: XOR with key (looped if shorter)
    - P-Box: Block permutation via custom bijective function
- Ensured padding with `0x00` to complete last block

The result is written to a binary file, block by block.

## Structure

- `src/`: Source and header files
- `Makefile`: Build script (`make`, `make run`, `make valgrind`)
- `README.md`: Project documentation
- `README` : Original README.md file for the assignment

## Build & Run

```bash
make               # Build the program
make run           # Run the main program with input file
make valgrind      # Run Valgrind for memory check
```

## Course Info

📚 **Computer Programming (CB & CD)** — 2024  
🧠 **Task Score:** 100/100
