# 0x0B. C - malloc, free
## About
An introductory project on:
- The difference between automatic and dynamic allocation
- Why and when to use `malloc` and `free`
- How to use `valgrind`
## Requirements
- Ubuntu 20.04 LTS
- gcc 12.2.0
- not allowed to use global variables
- the only C standard library functions allowed are malloc and free
## File Descriptions
### Mandatory
**[0-create_array.c](0-create_array.c)** - function that creates an array of chars, and initializes it with a specific char.

**[1-strdup.c](1-strdup.c)** - function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.

**[2-str_concat.c](2-str_concat.c)** - function that concatenates two strings.

**[3-alloc_grid.c](3-alloc_grid.c)** - function that returns a pointer to a 2 dimensional array of integers.

**[4-free_grid.c](4-free_grid.c)** - function that frees a 2 dimensional grid previously created by the function found in [3-alloc_grid.c](3-alloc_grid.c).

**[100-argstostr.c](100-argstostr.c)** - function that concatenates all the arguments of the program.

### Advanced
**[101-strtow.c](101-strtow.c)** - function that splits a string into words.
