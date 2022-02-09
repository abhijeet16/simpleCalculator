# Simple Calculator
This is a simple calculator that can add, subtract and multiply values in a set of registers.

The syntax for allowed operations are below:
1. `<register> <operation> <value>`
2. `print <register>`
3. `quit`

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
simpleCalculator.exe filePath
```
Input files are present in Inputs folder.
The program in this case terminates automatically after execution.
