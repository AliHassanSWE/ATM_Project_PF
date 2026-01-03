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
###  you just need to double tab this file:


<img width="750" height="600" alt="image" src="https://github.com/user-attachments/assets/a7b980c4-50bd-43a3-bad7-c76ddc6be8e5" />



###  It will automatically compile and run the program and show this screeen:


<img width="700" height="500" alt="image" src="https://github.com/user-attachments/assets/036c9bcf-5c32-40d6-a538-f8a0c18c99b6" />



###  when you enter any key it show main menu and for admin login username is "admin" Password "admin123"



<img width="700" height="500" alt="image" src="https://github.com/user-attachments/assets/132889ce-1a63-4107-bc14-afcfc0e0096f" />



###For customer login you need to type id which is assigned by rand function in csv and then enter pin you already assign during sinup
if it will be verified it will show you customer login:


<img width="650" height="501" alt="image" src="https://github.com/user-attachments/assets/e95dd9cd-3f9d-4b4b-872f-6cf5adc491a2" />


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

### how to paste the link to run:


<img width="1907" height="960" alt="image" src="https://github.com/user-attachments/assets/61c389d7-84e9-4c79-9746-0614c2ca8a51" />  



###  After pasting link press enter to run it will look like imges which is below:


<img width="1896" height="759" alt="image" src="https://github.com/user-attachments/assets/cc6cde42-c8d3-411f-a9c4-032d50240b88" />



###  when you enter any key it will show main menu like this:


<img width="903" height="407" alt="image" src="https://github.com/user-attachments/assets/ad1033e3-07c9-45dc-a7ee-92807e2ce18d" />


###  The 'CSV' file data looks like which i mentioned above:


<img width="1407" height="678" alt="image" src="https://github.com/user-attachments/assets/972c353c-3c22-417e-a622-23bac8831d46" />




