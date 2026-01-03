#ifndef ATM_SYSTEM_H
#define ATM_SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

// Global Variables
extern string fileName;
extern string adminUser;
extern string adminPass;
const string ADMIN_USER = "admin";
const string ADMIN_PASS = "admin123";

// Menu/Main Functions
void signup();
void login();
void adminLogin();
void forgotPin();
// User Functions
void userMenu(string accNum, string name, string pin, string phone, int balance);

// Admin Functions
void adminMenu();
void viewAllUsers();
void searchUser();
void deleteUser();
void editUser();
void resetUserPin();

// Helper Functions
void updateBalanceInFile(string targetAcc, int newBalance);
/*
CSV NUMBERINGING AND FORMAT:
 * DATABASE FORMAT (users.csv):
 * Column 1: Account Number (Unique ID)
 * Column 2: Full Name
 * Column 3: PIN Code
 * Column 4: Phone Number
 * Column 5: Current Balance
 */
#endif

// read the readme.txt or readme.md file to run the project properly