This project has been created as part of the 42 curriculum by Bchiang

ft_printf

Description

`ft_printf` is a reimplementation of the standard C library function `printf`.  
The goal of this project is to understand and reproduce the core mechanics of formatted output in C, including variadic functions, format string parsing, and number base conversion, without relying on the standard `printf` implementation.

This implementation supports a limited subset of format specifiers and focuses on correctness, memory safety, and compliance with the 42 Norminette.

Supported Features

The following format specifiers are implemented:

- `%c` : character
- `%s` : string
- `%p` : pointer address (hexadecimal)
- `%d` / `%i` : signed decimal integer
- `%u` : unsigned decimal integer
- `%x` : lowercase hexadecimal
- `%X` : uppercase hexadecimal
- `%%` : literal percent sign

Unsupported features include flags, field width, precision, and floating-point conversions.

Instructions

Compilation

Compile all source files using:

cc -Wall -Wextra -Werror *.c

If a Makefile is provided:

make

Usage

Include the header file and call ft_printf as you would printf:

E.g. 

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "world", 42);
    return (0);
}

Algorithm and Data Structures
Overall Algorithm

The format string is processed character by character.
If the current character is not %, it is written directly using write().
If a % is encountered:
If followed by another %, a literal % is printed.
Otherwise, the following character is treated as a format specifier.
Based on the specifier, the corresponding helper function is called.
Each helper function prints its output and returns the number of characters written.
ft_printf accumulates and returns the total character count.

Variadic Arguments Handling

The project uses <stdarg.h> and the macros:

va_start
va_arg
va_end
Arguments are retrieved only when required, ensuring correct order and type safety.
Characters are promoted to int due to C’s default argument promotions.

Number Conversion Strategy

Numbers are converted manually without using printf, itoa, or similar helpers.
Conversion is done using repeated division and modulo:
n % base extracts the least significant digit
n /= base shifts the number
Digits are stored in a buffer in reverse order, then written back from the end to ensure correct output order.
Base 10 is used for decimal conversions, base 16 for hexadecimal.
Uppercase and lowercase hexadecimal are handled using different digit sets.

This approach avoids recursion, minimizes memory usage, and ensures predictable behavior.

Data Structures

Fixed-size character buffers are used for number conversion.
No dynamic data structures (lists, trees, etc.) are required.
All memory usage is controlled and minimal.

Technical Choices

write() is used exclusively for output to comply with project constraints.
Helper functions are separated by responsibility (characters, strings, numbers, pointers).
Pointer values are cast to unsigned long to safely handle address printing.
NULL pointers are handled explicitly to match expected behavior.

Resources
References

man 3 printf
man 3 write
man 3 stdarg
GNU C Library documentation
42 intra materials on variadic functions

Use of AI

AI tools were used only as a learning aid, including:
Clarifying concepts related to variadic functions and argument promotion
Explaining base conversion logic and formatting behavior
Reviewing logic for correctness and edge cases
All code was written, tested, and validated manually by the author.

Author
Bchiang 42 School

