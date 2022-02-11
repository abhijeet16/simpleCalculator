# Simple Calculator
This is a simple calculator that can add, subtract and multiply values in a set of registers.

The syntax for allowed operations are below:
1. `<register> <operation> <value>`
2. `print <register>`
3. `quit`

### Sample Command
A add 2 <br/>
A ADD 3 <br/>
print A <br/>
B add 5 <br/>
B subtract 2 <br/>
print B <br/>

`Output` <br/>
5 <br/>
3 <br/>

`quit` or `QUIT` terminates the program

### How to set up (Windows)
Requirements: The GNU C++ compiler(g++) is needed. <br/>
To install C++ compiler:
1. Please visit "https://sourceforge.net/projects/mingw/", download and install.
2. It installs in C: drive (by default).
3. Add "C:\minGW\bin" to system variable
4. To confirm, if installed, check the below command in command prompt.

```
g++ --version
```

Once the installation is complete.
Navigate to the repository folder with `simpleCalculator.cpp` file and launch command prompt.
```
g++ -std=gnu++11 simpleCalculator.cpp -o simpleCalculator.exe
```
The command above will help in generating the executable file. To run this file, please follow the instructions below.

### How to run
There are two ways to run.
1. Without input file 
```
simpleCalculator.exe
```
In this way, inputs can be provided once .exe file runs.
To terminate the program `quit` or `QUIT` command is needed.

2. With input files
```
simpleCalculator.exe <filePath>
```
Input files are present in Inputs folder.
The program in this case terminates automatically after execution. <br/>
Input file need not have `quit` or `QUIT` command.

### About Calculator
* This simple calculator is case insensitive with it's operands. `A add 2` and `A ADD 2` both are valid commands.
* It doen't allow to keep a full numeric register name.
`12 multiply 3`, is not a valid command.
* It doesn't allow to perform operation on the same register. `B add B` is not a valid command.

### Possible Enhancements
* Check circular dependency.
* Allow operations with negative integers.
 
