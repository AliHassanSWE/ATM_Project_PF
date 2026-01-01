#include "atm_system.h"

void showMainMenu() {
    int choice;
    do {
        cout << "\n====================================\n";
        cout << "      ATM MANAGEMENT SYSTEM         \n";
        cout << "====================================\n";
        cout << "1. Customer Login\n";
        cout << "2. Create New Account (Signup)\n";
        cout << "3. Admin Login\n";
        cout << "4. Forgot PIN\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
if (!(cin >> choice)) {
    cout << "Please enter numbers only!" << endl;
    cin.clear();
    cin.ignore(10000, '\n'); 
    system("pause");
    continue; 
}

        switch (choice) {
            case 1: login(); break;
            case 2: signup(); break;
            case 3: adminLogin(); break;
            case 4: forgotPin(); break;
            case 0: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

void signup() {
    string name, pin, phone, accountNum;
    int initialBalance;
    cout << "\n===== CREATE ACCOUNT ======\n";
    int randomID = 10000 + (rand() % 90000); 
    accountNum = to_string(randomID);
    cout << "Enter FULL Name: "; 
    cin.ignore();
    getline(cin, name);
    cout << "Create 4-digit PIN: "; cin >> pin;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Initial Deposit: "; cin >> initialBalance;

    ofstream file(fileName.c_str(), ios::app);
    if (!file) {
        cout << "Error opening file!\n";
    } else {
        file << accountNum << "," << name << "," << pin << "," << phone << "," << initialBalance << endl;
        cout << "\nSUCCESS! Your Account Number: " << accountNum << endl;
        file.close();
    }
}

void forgotPin() {
    system("cls");
    string searchAcc, searchPhone;
    string acc, name, pin, phone, balance; 
    bool found = false;

    cout << "Enter Your Account Number: ";
    cin >> searchAcc;
    cout << "Enter Your Registered Phone Number: ";
    cin >> searchPhone;

    ifstream inFile("users.csv");
    if (!inFile) {
        cout << "Error: users.csv file not found!" << endl;
        system("pause");
        return;
    }
    while (getline(inFile, acc, ',')) {
        getline(inFile, name, ',');
        getline(inFile, pin, ',');
        getline(inFile, phone, ',');
        getline(inFile, balance); 

        if (acc == searchAcc && phone == searchPhone) {
            cout << "\n-------------------------------------" << endl;
            cout << " Verification Successful!" << endl;
            cout << " Hello, " << name << endl;
            cout << " Your PIN is: " << pin << endl;
            cout << "-------------------------------------" << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "\nError: Account Number and Phone Number do not match!" << endl;
    }

    inFile.close();
    cout << "\n";
    system("pause"); 
}

// 2. UPDATED LOGIN 
void login() {
    string inputAcc, inputPin;
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;

    while (attempts < MAX_ATTEMPTS) {
        cout << "====================================";
        cout << "\n====CUSTOMER LOGIN ====" << endl;
        cout << "=====================================" << endl;
        cout << "Enter Account Number: "; cin >> inputAcc;
        cout << "Enter PIN (Attempt " << (attempts + 1) << " of " << MAX_ATTEMPTS << "): "; cin >> inputPin;

        ifstream file(fileName.c_str());
        string f_acc, f_name, f_pin, f_phone, f_bal;
        bool found = false;

        while (getline(file, f_acc, ',')) {
            getline(file, f_name, ',');
            getline(file, f_pin, ',');
            getline(file, f_phone, ',');
            getline(file, f_bal, '\n');

            if (f_acc == inputAcc && f_pin == inputPin) {
                found = true;
                file.close();
                userMenu(f_acc, f_name, f_pin, f_phone, stoi(f_bal));
                return; 
            }
        }
        file.close();

        attempts++;
        if (attempts < MAX_ATTEMPTS) {
            cout << "Wrong PIN! " << (MAX_ATTEMPTS - attempts) << " attempts remaining." << endl;
            cout << "Forgot PIN? (yes/no): ";
            char choice; cin >> choice;
            cin.ignore(1000, '\n');
            if (choice == 'y' || choice == 'Y') {
                forgotPin(); // Calling the function we defined above
                return;
            }
        }
    }
    cout << "\n****************************************" << endl;
    cout << "   BANNED: Too many failed attempts!   " << endl;
    cout << "****************************************" << endl;
}

void userMenu(string accNum, string name, string pin, string phone, int balance) {
    int choice, amount;
    do {
        cout << "\n=========================" << endl;
        cout << "\n****** USER MENU ********" << endl;
        cout << "=========================" << endl;
        cout << "\nWelcome " << name << "!" << endl;
        cout << "1. Check Balance\n2. Withdraw Amount \n3. Deposit Cash\n0. Logout\nChoice: ";
        cin >> choice;
        if (choice == 1) cout << "Balance: " << balance << endl;
        else if (choice == 2) {
            cout << "Amount: "; cin >> amount;
            if (amount <= balance) { balance -= amount; updateBalanceInFile(accNum, balance); }
        } else if (choice == 3) {
            cout << "Amount: "; cin >> amount;
            balance += amount; updateBalanceInFile(accNum, balance);
        }
    } while (choice != 0);
}

//read the readme.txt or readme.md file to run the project properly