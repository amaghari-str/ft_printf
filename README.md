			*This project has been created as part of the 42 curriculum by amahari.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C library function `printf`. The goal of the project is to learn how variadic functions work in C, how to parse a format string, and how to structure code so that it stays clean, modular and easy to extend.

The function is declared as:

```c
int ft_printf(const char *format, ...);
```

It writes formatted output to the standard output and returns the total number of characters printed (or a negative value on a write error), just like the original `printf`.

The project is compiled into a static library, `libftprintf.a`, which can be linked into other programs.

### Supported conversions

| Specifier | Description                                          |
|-----------|------------------------------------------------------|
| `%c`      | A single character                                   |
| `%s`      | A string (prints `(null)` if the pointer is `NULL`)  |
| `%p`      | A pointer in hexadecimal form (`(nil)` for `NULL`)   |
| `%d`      | A signed decimal integer                             |
| `%i`      | A signed decimal integer                             |
| `%u`      | An unsigned decimal integer                          |
| `%x`      | An unsigned integer in lowercase hexadecimal         |
| `%X`      | An unsigned integer in uppercase hexadecimal         |
| `%%`      | A literal percent sign                               |

## Instructions

### Requirements

- A Unix-like system (Linux or macOS)
- `cc` (or `gcc` / `clang`)
- `make`

### Compilation

From the root of the repository:

```bash
make
```

This produces the static library `libftprintf.a`.

Available Makefile rules:

| Rule        | Action                                                  |
|-------------|---------------------------------------------------------|
| `make`      | Builds `libftprintf.a`                                  |
| `make clean`| Removes the object files                                |
| `make fclean`| Removes the object files and `libftprintf.a`           |
| `make re`   | Rebuilds everything from scratch                        |

The code is compiled with the flags `-Wall -Wextra -Werror`.

### Usage

Include the header in your source file and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, number: %d, hex: %x, ptr: %p\n",
                    "world", 42, 255, &len);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structures

### Overall algorithm

The implementation is a single linear pass over the format string, driven by a simple dispatch mechanism:

1. Initialize a `va_list` with `va_start` and a counter of printed characters set to zero.
2. Iterate over the format string character by character.
3. If the current character is not `%`, write it directly to the standard output and increment the counter.
4. If the current character is `%`, look at the next character (the conversion specifier) and call the dedicated handler for it (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`). The handler retrieves its argument with `va_arg`, prints it and returns the number of characters it wrote.
5. Add the value returned by the handler to the counter.
6. When the end of the string is reached, call `va_end` and return the counter.

Number conversion is done recursively: a number is divided by its base, the function is called on the quotient, and then the digit corresponding to the remainder is printed. This naturally prints the digits in the correct order (most significant first) without having to reverse a string.

### Why this approach

- **Single pass, O(n) complexity.** Every character of the format string and of every argument is processed exactly once, so the running time is linear in the size of the output.
- **No intermediate buffer and no dynamic allocation.** Characters are written directly with `write`. This removes any risk of memory leaks or allocation failures and keeps the function simple and safe. The trade-off is a larger number of `write` system calls compared to a buffered approach, which is acceptable for the scope of this project and keeps the behavior predictable (no need to flush a buffer at the end or on error).
- **One handler per conversion.** Each specifier is isolated in its own small function. This respects the Norm constraints on function length, makes every conversion easy to test separately, and allows new specifiers to be added by writing one function and adding one branch to the dispatcher.
- **Counting through return values.** Each handler returns the number of characters it printed, so the total is computed naturally without global variables, which keeps the function reentrant.
- **Recursive base conversion.** A single function handles all numeric conversions by taking the base and the character set as parameters (`0123456789` for decimal, `0123456789abcdef` or `0123456789ABCDEF` for hexadecimal). This avoids code duplication between `%d`, `%i`, `%u`, `%x`, `%X` and `%p`.

### Data structures

The project deliberately uses no complex data structures, because none are needed for this problem:

- **`va_list`** (from `<stdarg.h>`): the standard mechanism to access the variable number of arguments one by one.
- **Constant strings** used as digit tables (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`): they allow converting a digit value to its character with a direct array access, in O(1).
- **Fixed-width unsigned types** (`unsigned int`, `unsigned long`): `%u`, `%x` and `%X` use `unsigned int`; `%p` uses `unsigned long` (the pointer value cast to an integer) so that the full address fits. Signed values for `%d` and `%i` are handled by printing a minus sign and working on a positive value, with a special case for `INT_MIN` to avoid overflow.

Special cases are handled explicitly: a `NULL` string prints `(null)`, a `NULL` pointer for `%p` prints `(nil)`, and `%%` prints a single `%`.

## Resources

### References

- `man 3 printf` - description of the original function and its conversions
- `man 3 stdarg` - macros `va_start`, `va_arg`, `va_end`, `va_copy`
- `man 2 write` - the system call used for output
- [GNU C Library manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: Variadic arguments](https://en.cppreference.com/w/c/variadic)
- [cppreference: printf, fprintf, sprintf](https://en.cppreference.com/w/c/io/fprintf)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)

### Use of AI

AI was used as a helper tool and not as a replacement for understanding the project. It was used for:

- Writing and structuring this `README.md` file.

The implementation of the code itself, the algorithm design and the debugging were done by the author.
