@echo off
SETLOCAL
REM TheDarkTiger, 2023

set "PRGMNAME=XIBRIFI"
REM set "PATH=%~dp0"
REM set "BUILD=%PATH%build\"
set "BUILD=build\"

REM 
set "COMPILER=gcc"
set "COMPILER_OPTIONS=-O0 -W -Wall -pedantic"

REM 
set "LINKER=%COMPILER%"
set "LINKER_OPTIONS="


REM Householding
if not exist "%BUILD%" (
	echo Creating build folder...
	mkdir "%BUILD%"
)
if exist "%BUILD%*.o" (
	echo Removing old files...
	del "%BUILD%*.o"
)


REM Compile
echo Compile...

set FILES=main
(for %%f in (%FILES%) do (
	echo  %%f.c
	%COMPILER% %COMPILER_OPTIONS% -c -o "%BUILD%%%f.o" "%%f.c"
))


if exist "%BUILD%main.o" (
	echo Linking...
	%LINKER% -o "%BUILD%%PRGMNAME%.exe" "%BUILD%main.o"
) else (
	echo\
	echo ### No object file available to link ###
)


if exist "%BUILD%%PRGMNAME%.exe" (
	echo Copying program...
	copy /Y /V "%BUILD%%PRGMNAME%.exe" "%PRGMNAME%.exe"
) else (
	echo\
	echo ### No program generated ###
)
