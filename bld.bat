@echo off
@cls
setlocal EnableDelayedExpansion

:: Create directories if they don't exist
if not exist ".\bin" mkdir ".\bin"
if not exist ".\build" mkdir ".\build"

:: Define all exe names
set "CLANG_C_EXE=.\bin\clang_c.exe"
set "CLANG_CPP_EXE=.\bin\clang_cpp.exe"
set "CL_C_EXE=.\bin\cl_c.exe"
set "CL_CPP_EXE=.\bin\cl_cpp.exe"

:: Common flags for both compilers
set "COMMON_CLANG_FLAGS=-Wall -Wextra"
set "COMMON_CL_FLAGS=/W4 /WX /nologo /Fo./build/"

if "%1" == "" (
    :: C compilation
    echo Building C with Clang...
    clang -std=c2x %COMMON_CLANG_FLAGS% capp.c -o %CLANG_C_EXE%
    echo Building C with MSVC...
    cl capp.c %COMMON_CL_FLAGS% /Fe:%CL_C_EXE% /TC /std:c17
    @echo Built C executables
) else (
    :: C++ compilation
    echo Building C++ with Clang...
    clang -std=c++23 %COMMON_CLANG_FLAGS% cppapp.cpp -o %CLANG_CPP_EXE%
    echo Building C++ with MSVC...
    cl cppapp.cpp %COMMON_CL_FLAGS% /Fe:%CL_CPP_EXE% /TP
    @echo Built C++ executables
)

:: Clean up MSVC temporary files if they ended up in current directory
if exist *.obj del *.obj
if exist *.pdb move *.pdb .\build\

endlocal