@REM # GCC
@REM gcc -std=c17 program.c

@REM # Clang
@REM clang -std=c17 program.c
@REM error: invalid value 'c23' in '-std=c23'
@REM note: use 'c89', 'c90', or 'iso9899:1990' for 'ISO C 1990' standard
@REM note: use 'iso9899:199409' for 'ISO C 1990 with amendment 1' standard
@REM note: use 'gnu89' or 'gnu90' for 'ISO C 1990 with GNU extensions' standard
@REM note: use 'c99' or 'iso9899:1999' for 'ISO C 1999' standard
@REM note: use 'gnu99' for 'ISO C 1999 with GNU extensions' standard
@REM note: use 'c11' or 'iso9899:2011' for 'ISO C 2011' standard
@REM note: use 'gnu11' for 'ISO C 2011 with GNU extensions' standard
@REM note: use 'c17', 'iso9899:2017', 'c18', or 'iso9899:2018' for 'ISO C 2017' standard
@REM note: use 'gnu17' or 'gnu18' for 'ISO C 2017 with GNU extensions' standard
@REM note: use 'c2x' for 'Working Draft for ISO C2x' standard
@REM note: use 'gnu2x' for 'Working Draft for ISO C2x with GNU extensions' standard 

@REM # MSVC
@REM cl program.c

@echo off
setlocal EnableDelayedExpansion

:: Add specific compiler warning flags
set "COMMON_FLAGS=-Wall -Wextra"

if "%1" == "" (
clang -std=c2x %COMMON_FLAGS% capp.c -o ./bin/capp.exe

@echo Built capp.exe using C
) else (
clang -std=c++23 %COMMON_FLAGS% cppapp.cpp -o ./bin/cppapp.exe

@echo Built cppapp.exe using CPP
)

endlocal