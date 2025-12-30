README: How to Run the ATM Management System

Because This is a  multi-file C++ project. Follow these steps to compile and run the program correctly.

Method 1: Using the run.bat Script 

If you are on Windows and have MinGW (g++) installed:
Go to desktop or where is your project folder means outside of vscode open folder and then
Double-click the file named run.bat. or simply run file. 
A command window will open, compile the code automatically, and start the ATM program.
        Note: Do not run this from inside the VS Code terminal; run it directly from your file folder.

Method 2: Using the Command Line 

                This is manual way and good option if run.bat is working. 
If you prefer using the terminal or the .bat file isn't working, use this command:
1. Open your terminal or command prompt (CMD).
2. Navigate to the project folder.
3. Copy and paste the  command i give below:
    g++ main.cpp user_logic.cpp admin_logic.cpp helper_logic.cpp
    and press enter
(Important )
    Once compiled, type ./ATM_System and press Enter to start.




Method 3: Using an IDE (Dev-C++ / Code::Blocks)
Since this project uses multiple files, you cannot just open main.cpp and hit run. You must create a project:
Open your IDE and go to File > New > Project.
Select Console Application (C++).
Right-click on the Project name in the sidebar and select Add Files.
Select all 5 files: atm_system.h, main.cpp, user_logic.cpp, admin_logic.cpp, and helper_logic.cpp.
Click Build and Run (usually F11 or F9).