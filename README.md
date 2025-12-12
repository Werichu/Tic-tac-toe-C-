# Tic-tac-toe-C-
This's a my first project, i hope update it to acceptable state, however, if you plan to modify it or use it for another purpose, you are completely free to do so :)


#### Structure Proyect #####

Tic-Tac-Toe/
 ├─ src/
 │   └─ main.cpp
 ├─ include_files/
 │   ├─ Estructura.h
 │   ├─ Logica.h
 |   └─ utils.h
 ├─ build/
 |
 └─ CMakeLists.txt

## Requirements ##

Before you compiling, you need:

- g++ or clang
- cmake >= 3.10
- make

Fast Instalation on linux: 

'''bash

sudo apt install g++ cmake make

Instalation on windows: 

MinGW or Visual Studio Build Tools
CMake (https://cmake.org/)

---HOW TO COMPILING THE PROJECT (Linux / Windows)---

1. Clone the repository

	* git clone https://github.com/YOUR-USER/Tic-tac-toe-C-.git 
	* cd Tic-tac-toe-C-

2. In the "build" carpet execute "cmake .. "
	* cd build
	* cmake .. 

3. compile
	* make

4. Execute
	* ./tictactoe

## On Windows (MinGW) ##
	* mkdir build
	* cd build
	* cmake -G "MinGW Makefiles" ..
	* mingw32-make
	* .\tictactoe.exe

//Notes

	* If you add new .cpp files, you must add them to CMakeLists.txt
	* If cmake fails..., check that you are inside the build folder.

---HOW TO CONTRIBUTE---

	* Clone this repository.
	* Create a new branch with `git switch -c <v1.3......"`
	`v...."` refers to the version number that the program will be updated to.
	* git push origin <Your-branch name>


## Autor
	Werichu



