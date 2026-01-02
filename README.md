# ATM Management System – Programming Fundamentals Project

A complete console-based ATM Management System built in C++ that work like  real-world banking operations. This project uses file handling (CSV) to store user data permanently and features distinct panels for Users and Administrators.

####  ======§§§§§§§§§=========

##  Student Information

* **Name:** Ali Hassaan
* **Section:** BSCS_**A** (Morning)
* **Roll No.:** 25021519-119
* **Instructor:** Dr. Nauman Riaz
* **Course:** Programming Fundamentals (CS-102)

###  =======•==•====•==•=======

##  Project Overview

This project demonstrates core programming concepts including **File I/O**, **Functions**, **Loops**, and **Conditional Logic** **File handling ** . It serves as a secure banking simulation where users can create accounts, withdraw/deposit money, and manage their security settings, while administrators can manage the entire project.

### Key Features

####  User Panel
* **Secure Login:** 5-attempt limit with account lockout protection.
* **Forgot PIN:** Logic to reset security credentials securely.
* **Transactions:** Deposit and Withdraw funds with real-time balance updates.
* **Account Management:** Users can view their details and update their profiles.
* - **Forgot PIN and  Recovery:** Allows users to recover their PIN by verifying their Account Number and registered Phone Number against the database.

#### Admin Panel
> **Note:** For testing purposes, use the following default credentials to access the Admin Panel:
> - **Username:** `admin`
> - **Password:** `admin123`
* **Dashboard:** View all registered users in the database.
* **Edit User:** Admins can modify User Names, PINs, and Phone Numbers.
* **Search & Delete:** specific tools to manage database records by Account Number.
* - **Admin PIN Reset:** A secure administrative tool that allows the admin to search for a user by Account Number and manually assign a new PIN in the database.

####  =========°°°==========

##  Data Storage (CSV Structure)

**Note:** The actual `users.csv` file is excluded from this repository for security and (simulated sensitive data). 

If you run this project locally, the system will read/write to a `users.csv` file. You can create one manually with the following header and format:

**File:** `users.csv`
```csv
AccountID,FullName,PIN,PhoneNumber,Balance
33572,Ali Hassan,1111,03001234567,30000
233573,Dr. Nauman Riaz,2222,03007654321,15000
```
##  Note on .gitignore

You will notice that `users.csv` and `.exe` files are missing from this repository. This is intentional:

1.  **`users.csv`**: Ignored for security. Your local machine will store your own private data separate from the public code. Means when different user use this project
they will not see others csv file they will see their own csv file.
3.  **`.exe`**: Ignored to force a fresh compilation on your system, preventing errors from mismatched file versions.
###  Security & Account Recovery
* **Forgot PIN Feature:** Added a secure way for users to recover their login credentials.
    * Users must verify their identity by providing their **Account Number** and **Registered Phone Number**.
    * If the data matches the database, the current PIN is revealed.
    
 ####  ==========<<<<<<<===================
##  How to Run

This project consists of multiple C++ source files (`main.cpp`, `admin_logic.cpp`, `user_logic.cpp`, `helper_logic.cpp`) that need to be linked and compiled together.

###  Method 1: Using `run.bat` (Recommended)
Included in the repository is a Windows Batch file named `run.bat`. This script automates the build process.
1.  Navigate to the project folder.
2.  Double-click **`run.bat`**.
3.  The script will automatically:
    * Compile all `.cpp` files using `g++`.
    * Clean up old build files.
    * Launch the `ATM_System.exe` immediately.
    * 
####  ===========^^^^==========
     
###  Method 2: Manual Compilation (Terminal)
If you wish to compile the code manually via VS Code Terminal or Command Prompt, use the following command to link all logic files:

**1. Compile the Source Code:**
Copy the block below, paste it into your terminal, and press enter.

```bash
g++ main.cpp admin_logic.cpp user_logic.cpp helper_logic.cpp -o ATM_System
```

2. ##  (Important)
3. After that, run the project with this command:

```bash
./ATM_System.exe
```

