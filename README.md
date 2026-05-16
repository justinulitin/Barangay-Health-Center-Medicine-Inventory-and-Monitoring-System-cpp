# Barangay Health Center Medicine Inventory System

![Language](https://img.shields.io/badge/language-C++-blue)
![Status](https://img.shields.io/badge/status-Completed-green)

## Overview

The Barangay Health Center Medicine Inventory System is a simple console-based C++ program designed to help barangay health centers organize and monitor medicine records. The system allows users to add medicines, update stock levels, check low stock medicines, and generate inventory reports.

This project was created as a beginner-friendly Data Structures and Algorithms project using basic C++ concepts and data structures.

---

# Features

* Add new medicine records
* View all stored medicines
* Update medicine stock
* Check low stock medicines
* Generate inventory reports
* Supports different medicine units such as:

  * tablets
  * capsules
  * mL
  * mg
  * grams
* Input validation and basic error handling

---

# Data Structures and Algorithms Used

## Data Structures

### Struct

The program uses a `struct` to store medicine information such as:

* name
* category
* stock
* maximum capacity
* unit
* expiry date

### Unordered Map (Hashing)

The system uses `unordered_map` to store medicine records using medicine IDs as keys.

This allows:

* fast searching
* fast updating
* efficient retrieval of records

---

## Algorithms and Techniques

* Hashing using `unordered_map`
* Iteration using loops
* Conditional statements for stock checking and validations
* Input validation and error handling
* Percentage computation for low stock monitoring

---

# Technologies Used

* C++
* Visual Studio Code / Dev-C++ / Code::Blocks
* Standard C++ Libraries

---

# How to Run the Program

## 1. Clone the Repository

```bash
git clone https://github.com/your-username/your-repository-name.git
```

## 2. Open the Project

Open the `.cpp` file using:

* Visual Studio Code
* Code::Blocks
* Dev-C++
* or any C++ compiler

## 3. Compile and Run

Example using g++:

```bash
g++ main.cpp -o inventory
./inventory
```

---

# Sample Menu

```text
======== BARANGAY HEALTH CENTER MEDICINE INVENTORY ========
1. Add Medicine
2. View Medicines
3. Update Stock
4. Check Low Stock Medicines
5. Generate Inventory Report
6. Exit
===========================================================
```

---

# Sample Medicine Record

| Field       | Example     |
| ----------- | ----------- |
| Medicine ID | M001        |
| Name        | Paracetamol |
| Category    | Tablet      |
| Stock       | 150         |
| Unit        | tablets     |
| Expiry      | 2027-05-20  |

---

# Error Handling Implemented

The system includes basic error handling such as:

* invalid menu input
* negative stock values
* duplicate medicine IDs
* stock exceeding maximum capacity
* invalid numeric input
* empty medicine IDs

---

# Future Improvements

Possible future improvements for the system:

* File handling for data saving
* Login system
* GUI version
* Expiry date monitoring
* Medicine dispensing records
* Recursion implementation for reports
* Sorting and searching features

---

# Learning Objectives

This project helped improve my understanding of:
- Structures in C++
- Hashing using unordered_map
- Input validation
- Inventory management logic
- Console-based systems

---

# Developer

Created by a First Year Computer Science Student as a Data Structures and Algorithms project.

---

# License

This project is for educational purposes only.
