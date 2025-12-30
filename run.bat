@echo off
echo Compiling ATM System...
g++ main.cpp user_logic.cpp admin_logic.cpp helper_logic.cpp -o ATM_System.exe

if %errorlevel% == 0 (
    echo Compilation Successful! Starting ATM...
    timeout /t 2 >nul
    ATM_System.exe
) else (
    echo.
    echo Compilation Failed! 
    pause
)
