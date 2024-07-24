# _printf

## Description

This project implements a custom [_printf](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c)
function in C, which mimics the behavior of the standard printf function. It supports a variety of format specifiers for different data types and includes a helper function, handle_format, to handle specific format specifiers.

## Compilation and Installation

### Compilation

To compile the [_printf](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) function along with any necessary helper functions, you can use the gcc compiler. Assuming all your source files are in the same directory, use the following command:

gcc -o printf_program main.c [_printf.c](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) handle_format.c print_functions.c

Replace main.c, _printf.c, handle_format.c, and print_functions.c with the actual names of your source files.

### Installation

Since this is a custom implementation and not a system library, you don't need a traditional installation process. Just ensure that the compiled binary is in your PATH or in the directory you're working from.

### Requirements

    • GCC Compiler: Ensure you have the GCC compiler installed. You can check by running gcc --version.
    • C Standard Library: The implementation relies on standard library functions like va_list and write.

### Example

Here is one example demonstrating how to use the custom [_printf](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) function:

### Example : Basic Usage

#include "[main.h](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/main.h")"  // Make sure to include the header file where [_printf](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) is declared


```
int main()
{
    _printf("Hello, %s!\n", "world");
    _printf("Character: %c\n", 'A');
    _printf("Decimal: %d\n", 123);
    _printf("Unsigned: %u\n", 123);
    _printf("Hexadecimal: %x\n", 0x7B);
    _printf("Pointer: %p\n", main);
    return 0;
} 
```

## Testing

To test the implementation, you can create a separate test file or include tests in your main function. Here's a simple example of how to structure tests:
Running Tests
Compile and run the test file as follows:

gcc -o test_printf test_printf.c [_printf.c](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) handle_format.c print_functions.c
./test_printf

This will run your tests and verify that your [_printf](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) implementation matches the expected output.

## Note

Make sure to implement the actual print* functions (e.g., printChar, printInt, etc.) that [_printf](https://github.com/SeasonofBeaver/holbertonschool-printf/blob/main/_printf.c) and handle_format rely on. These functions should handle the specifics of formatting and outputting each type of data.

## Author 

[@SeasonofBeaver](https://github.com/SeasonofBeaver)

[@MrKay12](https://github.com/MrKay12)
 
