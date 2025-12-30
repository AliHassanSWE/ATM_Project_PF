# ATM Management System – Programming Fundamentals Project

A complete console-based ATM Management System built in C++ that simulates real-world banking operations. This project uses file handling (CSV) to store user data permanently and features distinct panels for Users and Administrators.

====={{{{{{{{=========

## 🔗 Student Information

* **Name:** Ali Hassaan
* **Section:** A (Morning)
* **Roll No.:** 25021519-119
* **Instructor:** Dr. Nauman Riaz
* **Course:** Programming Fundamentals

=======•==•====•==•=======

##  Project Overview

This project demonstrates core programming concepts including **File I/O**, **Functions**, **Loops**, and **Conditional Logic**. It serves as a secure banking simulation where users can create accounts, withdraw/deposit money, and manage their security settings, while administrators can manage the entire database.

### Key Features

####  User Panel
* **Secure Login:** 5-attempt limit with account lockout protection.
* **Forgot PIN:** Logic to reset security credentials securely.
* **Transactions:** Deposit and Withdraw funds with real-time balance updates.
* **Account Management:** Users can view their details and update their profiles.

#### 🛠 Admin Panel
* **Dashboard:** View all registered users in the database.
* **Edit User:** Admins can modify User Names, PINs, and Phone Numbers.
* **Search & Delete:** specific tools to manage database records by Account Number.

=========°°°==========

##  Data Storage (CSV Structure)

**Note:** The actual `users.csv` file is excluded from this repository for security and (simulated sensitive data). 

If you run this project locally, the system will read/write to a `users.csv` file. You can create one manually with the following header and format:

**File:** `users.csv`
```csv
AccountID,FullName,PIN,PhoneNumber,Balance
33572,Ali Hassan,1111,03001234567,30000
233573,Dr. Nauman Riaz,2222,03007654321,15000
```
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
#===========^^^^==========
     
###  Method 2: Manual Compilation (Terminal)
If you wish to compile the code manually via VS Code Terminal or Command Prompt, use the following command to link all logic files:

**1. Compile the Source Code:**
bash copy the line below amd paste in terminal amd press enter. it will complie files
``` g++ main.cpp admin_logic.cpp user_logic.cpp helper_logic.cpp -o ATM_System```
#( Important) 
After that must paste this line to run the project in the same terminal
```ATM_System.exe```
