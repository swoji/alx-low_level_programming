## 0x03. C - Debugging
## About
An introductory project on:
- What is debugging
- What are some methods of debugging manually
- How to read the error messages
## Requirements
- Ubuntu 20.04 LTS
- gcc 12.2.0
## File Descriptions
### Mandatory
**[main.h](main.h)** - header file for [0-main.c](0-main.c), [2-largest_number.c](2-largest_number.c), and [3-print_remaining_days.c](3-print_remaining_days.c).

**[0-main.c](0-main.c)** - this file test that the function positive_or_negative() gives the correct output when given a case of 0.

**[1-main.c](1-main.c)** - comment out (don’t delete it!) the part of the code that is causing the output to go into an infinite loop.

**[2-largest_number.c](2-largest_number.c)** - program prints the largest of three integers.

**[3-print_remaining_days.c](3-print_remaining_days.c)** - program converts a date to the day of year and determines how many days are left in the year, taking leap year into consideration.
Fix the print_remaining_days() function so that the output works correctly for all dates and all leap years.
- Line count will not be checked for this task.
- You can assume that all test cases have valid months (i.e. the value of month will never be less than 1 or greater than    12) and valid days (i.e. the value of day will never be less than 1 or greater than 31).
- You can assume that all test cases have valid month/day combinations (i.e. there will never be a June 31st or November 31st, etc.), but not all month/day/year combinations are valid (i.e. February 29, 1991 or February 29, 2427).