# C++ - Module 00

## Namespaces, classes, member functions, stdio streams,initialization lists, static,const, and some other basic stuf

### EX00 - Megaphone

This program is a simple command-line utility that takes all of its command-line arguments, converts them to uppercase, and prints them to the console. If no arguments are provided, it prints a specific predifine message.

The program's logic is straightforward:

01. It checks if any command-line arguments were provided by the user. The program's name is always the first argument, so it checks for a count greater than one.

02. If arguments exist, it loops through each one, starting from the first argument provided by the user.

03. For each argument (word), it iterates through every character, converts it to its uppercase equivalent using the std::toupper function, and builds a new string.

04. After converting a full argument to uppercase, it prints the result to the standard output. A space is added between each argument for readability.

05. If no arguments are provided, the program executes a fallback else block, printing the predefine message to the console.

Code Explanation

* `main(int argc, char *argv[]) ` This is the standard entry point for a C++ program that handles command-line arguments.
`argc` (Argument Count) is an integer that holds the total number of arguments, including the program's name.
`argv` (Argument Vector) is an array of C-style strings `(char *)` where each element is one of the arguments. `argv[0]` is always the program's name, `argv[1]` is the first user-provided argument, and so on.

* `for(int i = 1; i < argc ; i++)` : The outer loop iterates through each command-line argument. It starts at index 1 to skip the program's name `(argv[0])`

* `argument.clear()` : This line is crucial. It resets the `std::string` variable argument at the beginning of each loop iteration, ensuring that the previous argument's content is not carried over and appended to the new one.

* `for(int j = 0; argv[i][j] != '\0'; j++)` : The inner loop iterates through the characters of the current argument. C-style strings are null-terminated, so the loop continues until it finds the `\0` character.

* `argument += static_cast<char>(std::toupper(argv[i][j])) `: This line does the actual conversion. It takes each character `argv[i][j]`, converts it to uppercase using `std::toupper`, and appends the result to the `argument` string.

How build and run

to compile the program using `c++ -Wall -Wextra -Werror -std=c++20 -O3` use `make`
```bash
# compile with flags c++ -Wall -Wextra -Werror -std=c++20 -O3
$>make
```
this will create the executable `megaphone` and the object file `megaphone.o` in the same directry

```bash
# run ls -l command
$>ls -l
Makefile  megaphone  megaphone.cpp  megaphone.o
```

then can run following tests to confirm the program generate expected results

test 01
```bash
$>./megaphone "shhhhh... I think the students are asleep..."
```
expected output
```bash
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```
test 02
```bash
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
```
expected output
```bash
DAMNIT  !  SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
```
test 03
```bash
$>./megaphone
```
expected output
```bash
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```
