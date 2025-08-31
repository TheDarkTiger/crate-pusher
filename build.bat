@echo off

SET GAME_NAME=CRATEPUSHER

SET "CC=D:\DEV_GB\gbdk\bin\lcc"
SET "SOURCE_DIR=src"
SET "BUILD_DIR=build"
SET "BIN_DIR=bin"

REM IF "%~1"=="clean" (GOTO Clean) ELSE (GOTO Unk)
IF "%~1"=="clean" (GOTO Clean)
IF "%~1"=="run" (GOTO Run)
IF "%~1"=="info" (GOTO Info)

REM Build
ECHO Build...

REM Clean
:Clean
ECHO Clean...
del /F /S /Q %BUILD_DIR%\*.*
GOTO Compile
GOTO End

REM Compile
:Compile
ECHO Compile...
"%CC%" -c -o "%BUILD_DIR%\main.o" "%SOURCE_DIR%\main.c"
GOTO Link
GOTO End

REM Link
:Link
ECHO Linking...
"%CC%" -o "%BUILD_DIR%\%GAME_NAME%.gb" "%BUILD_DIR%\main.o" -Wl-w -Wl-j
copy "%BUILD_DIR%\%GAME_NAME%.gb" "%BIN_DIR%\%GAME_NAME%.gb"
GOTO Info
GOTO End

REM Run
:Run
ECHO Run...
"D:\Program Files (x86)\bgb\bgb.exe" "%BIN_DIR%\%GAME_NAME%.gb"
GOTO End

REM Info
:Info
ECHO Info...
"D:\DEV_GB\gbdk\bin\romusage.exe" "%BUILD_DIR%\%GAME_NAME%.noi" -g -a
GOTO End

:End
REM pause
