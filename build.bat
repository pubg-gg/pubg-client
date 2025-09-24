@echo off
echo ===============================================
echo   PUBG Enhancement Tool - C++ Demo Builder
echo ===============================================
echo.
echo WARNING: This is a demonstration project only!
echo No actual game enhancement features provided.
echo.

:: Check for g++ compiler
echo Checking for g++ compiler...
g++ --version >nul 2>&1
if errorlevel 1 (
    echo ERROR: g++ compiler not found!
    echo Please install MinGW-w64 or MSYS2 to get g++
    echo.
    echo Download from: https://www.msys2.org/
    echo.
    pause
    exit /b 1
)

echo g++ compiler found!
echo.

:: Clean previous build
echo Cleaning previous build...
del /Q *.o pubg_demo.exe 2>nul

:: Build the project
echo Building C++ demo project...
echo.

echo Compiling main.cpp...
g++ -std=c++17 -Wall -Wextra -O2 -I. -c main.cpp -o main.o
if errorlevel 1 (
    echo ERROR: Failed to compile main.cpp
    pause
    exit /b 1
)

echo Compiling GameOverlay.cpp...
g++ -std=c++17 -Wall -Wextra -O2 -I. -c GameOverlay.cpp -o GameOverlay.o
if errorlevel 1 (
    echo ERROR: Failed to compile GameOverlay.cpp
    pause
    exit /b 1
)

echo Compiling SystemChecker.cpp...
g++ -std=c++17 -Wall -Wextra -O2 -I. -c SystemChecker.cpp -o SystemChecker.o
if errorlevel 1 (
    echo ERROR: Failed to compile SystemChecker.cpp
    pause
    exit /b 1
)

echo Linking executable...
g++ main.o GameOverlay.o SystemChecker.o -o pubg_demo.exe -luser32 -lkernel32
if errorlevel 1 (
    echo ERROR: Failed to link executable
    pause
    exit /b 1
)

echo.
echo ===============================================
echo Build completed successfully!
echo ===============================================
echo.
echo Running demo...
echo.

pubg_demo.exe

echo.
echo Demo completed.
echo.
pause