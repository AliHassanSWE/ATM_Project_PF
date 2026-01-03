#include "atm_system.h"
bool isNumeric(string s) {    // it tell Helper function to ensure inputs is PINs contain only digits
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}
void signup() {
    string name, pin, phone, accountNum;
    int initialBalance;
    cout << "\n===== CREATE ACCOUNT ======\n";
    int randomID = 10000 + (rand() % 90000); //It Generates a random 5-digit number between 10000 and 99999
    accountNum = to_string(randomID);
    cout << "Enter FULL Name: "; 
    cin.ignore();  // Clear the input buffer
    getline(cin, name);   // getline is used here to allow names with spaces (e.g., "Ali Hassan")
    do {
        cout << "Create 4-digit PIN (Numbers only): ";
        cin >> pin;
        
        if (!isNumeric(pin) || pin.length() != 4) {
            cout << "Error: PIN must be exactly 4 digits! Try again.\n";
        }
    } while (!isNumeric(pin) || pin.length() != 4);   // It create Strict Validation: Loops until the PIN is exactly 4 digits and numeric
  

    cout << "Enter Phone: "; cin >> phone; 
    do {
    cout << "Enter Initial Deposit: ";
    if (!(cin >> initialBalance)) {    //It will  Checks if user typed text instead of numbers for balance
        cin.clear(); cin.ignore(10000, '\n');
        initialBalance = -1; 
    }
    
    if (initialBalance < 0) {
        cout << "Error: Balance cannot be negative. Try again.\n";
    }
} while (initialBalance < 0);   // it make sure  New accounts cannot start with negative money

    ofstream file(fileName.c_str(), ios::app);  // It ensures we ADD to the file instead of overwriting it
    if (!file) {
        cout << "Error opening file!\n";
    } else {
        file << accountNum << "," << name << "," << pin << "," << phone << "," << initialBalance << endl; // Writes data as a comma-separated line (CSV standard) for easy reading
        cout << "\nSUCCESS! Your Account Number: " << accountNum << endl;
        file.close();
    }
}

// Function: forgotPin
  
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
        cout << "=====================================";
        cout << "\n    ==== CUSTOMER LOGIN ====       " << endl;
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
    do {  //it Keeps the User Dashboard open until they explicitly choose "0" to Logout
        cout << "\n=========================" << endl;
        cout << "\n****** USER MENU ********" << endl;
        cout << "=========================" << endl;
        cout << "\n  Welcome <<< " << name << " >>>>" << endl;
        cout << "\n1. Check Balance\n2. Withdraw Amount \n3. Deposit Cash\n0. Logout\nChoice: ";
        cin >> choice;
        if (choice == 1) cout << "Balance: " << balance << endl;
       
       else if (choice == 2) {
            cout << "Enter Amount to Withdraw: "; 
            cin >> amount;
            
            if (amount > balance) {
                cout << "\nERROR: Insufficient Balance! You only have " << balance << endl;
            } else if (amount <= 0) {
                 cout << "\nERROR: Invalid Amount!" << endl;
            } else {
                balance -= amount; 
                updateBalanceInFile(accNum, balance);   // It  Immediately saves the new balance to "users.csv" 
                
                // Success Messages
                cout << "\n-----------------------------------" << endl;
                cout << "   CONGRATULATION: Withdraw Successful!   " << endl;
                cout << "-------------------------------------" << endl;
                cout << "New Balance: " << balance << endl;
            }
        }
       
        else if (choice == 3) {
            cout << "Amount: "; cin >> amount;
            balance += amount; updateBalanceInFile(accNum, balance);  //It will Updates variable and file  so the user sees the change instantly
        }
    } while (choice != 0);
}

//read the readme.txt or readme.md file to run the project properly