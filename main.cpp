#include "atm_system.h"

// Define Global Variables once here
string fileName = "users.csv";

int main()
{
    srand(time(0));
    system("cls"); 
    cout << "\n\n";
    cout << "\t=============================================" << endl;
    cout << "\t||                                         ||" << endl;
    cout << "\t||      welcome to  ATM  SYSTEM            ||" << endl;
    cout << "\t||                                         ||" << endl;
    cout << "\t=============================================" << endl;
    cout << "\t||                                         ||" << endl;
    cout << "\t||   DEVELOPED BY:   Ali Hassan            ||" << endl;
    cout << "\t||   INSTRUCTOR:     Dr. Nauman Riaz       ||" << endl;
    cout << "\t||                                         ||" << endl;
    cout << "\t=============================================" << endl;
    cout << "\n\n\t   >>> Press Enter to Start Session <<<   ";
    cin.get();
    int choice;
    do
    {
        system("cls");
        cout << "\n=======================================\n";
        cout << "        ATM MANAGEMENT SYSTEM          \n";
        cout << "=======================================\n";
        cout << "\n 1. Customer Login\n";
        cout << " 2. Create New Account (Signup)\n";
        cout << " 3. Admin Login\n";
        cout << " 4. Forgot PIN\n";
        cout << " 0. Exit\n";
        cout << " Enter your choice: ";

        // Input Validation (To prevent infinite loop if user enters letters)
        if (!(cin >> choice))
        {
            cout << "Please enter numbers only!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            system("pause");
            choice = -1; // Force loop to restart
            continue;
        }

        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        case 3:
            adminLogin();
            break;
        case 4:
            forgotPin();
            break;
            cout << "\nThank you for using our ATM System.\n";
            cout << "Have a wonderful day!\n";
            exit(0);
            cout << "Exiting... Goodbye!\n";
        default:
            cout << "Invalid choice! Please try again.\n";
            system("pause");
        }
    } while (choice != 0);
    return 0;
}

// read the readme.txt or readme.md file to run the project properly