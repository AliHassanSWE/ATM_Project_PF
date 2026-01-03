#include "atm_system.h"

// Function: updateBalanceInFile
void updateBalanceInFile(string targetAcc, int newBalance)
{
    ifstream inFile(fileName.c_str());
    ofstream outFile("temp.csv");
    string f_acc, f_name, f_pin, f_phone, f_bal;

    while (getline(inFile, f_acc, ','))
    {
        getline(inFile, f_name, ',');
        getline(inFile, f_pin, ',');
        getline(inFile, f_phone, ',');
        getline(inFile, f_bal, '\n');

        if (f_acc == targetAcc)
        {
            outFile << f_acc << "," << f_name << "," << f_pin << "," << f_phone << "," << newBalance << endl;
        }
        else
        {
            outFile << f_acc << "," << f_name << "," << f_pin << "," << f_phone << "," << f_bal << endl;
        }
    }
    inFile.close();
    outFile.close();
    remove(fileName.c_str()); 
    rename("temp.csv", fileName.c_str());
}

// read the readme.txt or readme.md file to run the project properly