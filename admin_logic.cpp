#include "atm_system.h"

void adminLogin() {
    string u, p;
    cout << "\n--- ADMIN LOGIN ---\nUsername: "; cin >> u;
    cout << "Password: "; cin >> p;
    if(u == adminUser && p == adminPass) adminMenu();
    else cout << "Access Denied!\n";
}

void adminMenu() {
    int choice;
    do {
        cout << "\n--- ADMIN DASHBOARD ---\n1. View All users\n2. Search user\n3. Delete user\n4. Edit user account\n0. Logout\n MAKE Your Choice: ";
        cin >> choice;
        switch(choice) {
            case 1: viewAllUsers(); break;
            case 2: searchUser(); break;
            case 3: deleteUser(); break;
            case 4: editUser(); break;
        }
    } while (choice != 0);
}

void viewAllUsers() {
    ifstream file(fileName.c_str());
    string line;
    while (getline(file, line)) cout << line << endl;
    file.close();
}

void searchUser() {
    string searchAcc, f_acc, line;
    cout << "Enter Acc: "; cin >> searchAcc;
    ifstream file(fileName.c_str());
    while (getline(file, f_acc, ',')) {
        getline(file, line); 
        if (f_acc == searchAcc) cout << "Found: " << f_acc << "," << line << endl;
    }
    file.close();
}

void deleteUser() {
    string targetAcc, f_acc, f_rest;
    bool found = false; // 1. Create a flag to track success

    cout << "Enter Acc to Delete: "; cin >> targetAcc;
    
    ifstream inFile(fileName.c_str());
    ofstream outFile("temp.csv");

    while (getline(inFile, f_acc, ',')) {
        getline(inFile, f_rest);

        if (f_acc != targetAcc) {
            // If it's NOT the target, copy it to the new file
            outFile << f_acc << "," << f_rest << endl;
        } else {
            // If it IS the target, we skip writing it (deleting it)
            // and set our flag to true
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove(fileName.c_str());
    rename("temp.csv", fileName.c_str());

   
    if (found) {
        cout << "Deleted account successfully: " << targetAcc << endl;
    } else {
        cout << "Account not found!" << endl;
    }
}

void editUser() {
    string targetAcc, newName, newPin, newPhone;
    cout << "\n--- ADMIN: EDIT USER ACCOUNT ---" << endl;
    cout << "Enter Account Number to Edit: "; 
    cin >> targetAcc;

    ifstream file(fileName.c_str());
    ofstream tempFile("temp.csv"); // Creates a temporary database
    
    string f_acc, f_name, f_pin, f_phone, f_bal;
    bool found = false;

    // Read the file line by line
    while (getline(file, f_acc, ',')) {
        getline(file, f_name, ',');
        getline(file, f_pin, ',');
        getline(file, f_phone, ',');
        getline(file, f_bal, '\n');

        if (f_acc == targetAcc) {
            found = true;
            cout << "Account Found!" << endl;
            
            // 1. Get New Name
            cout << "Current Name: " << f_name << " | Enter New Name: ";
            cin.ignore(); 
            getline(cin, newName);

            // Write the UPDATED data to the temporary file
            tempFile << f_acc << "," << newName << "," << newPin << "," << newPhone << "," << f_bal << endl;
        } else {
            // Write the UNCHANGED data for other users to the temporary file
            tempFile << f_acc << "," << f_name << "," << f_pin << "," << f_phone << "," << f_bal << endl;
        }
    }

    file.close();
    tempFile.close();

    // Delete the old file and rename the temporary one to users.csv
    remove(fileName.c_str());
    rename("temp.csv", fileName.c_str());

    if (found) {
        cout << "\nSUCCESS: Account " << targetAcc << " updated successfully!" << endl;
    } else {
        cout << "\nERROR: Account Number not found in database." << endl;
    }
}


//read the readme.txt or readme.md file to run the project properly