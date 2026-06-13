# Monty

## Description
Monty 0.98 is a scripting language that is first compiled into Monty ByteCode.
This project is an interpreter for Monty ByteCode files written in C.
It uses a stack (LIFO) data structure.

## Repository
- **GitHub repository:** monty

## Files
| File | Description |
|------|-------------|
| `monty.h` | Header file with structs and function prototypes |
| `main.c` | Entry point, file reading, and opcode dispatcher |
| `opcode_funcs.c` | All opcode implementations |
| `Makefile` | Compilation rules |

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
or simply:
make

## Usage
./monty <file.m>

## Opcodes Implemented

| Opcode | Description |
|--------|-------------|
| `push <int>` | Pushes an integer onto the stack |
| `pall` | Prints all values on the stack from top to bottom |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `add` | Adds the top two elements; result replaces second, top is removed |
| `nop` | Does nothing |
| `div` | Divides second top element by top element |
| `mul` | Multiplies second top element by top element |

## Example
$ cat bytecodes/00.m

push 1

push 2

push 3

pall

$ ./monty bytecodes/00.m

3

2

1

## Author
Tajudeen - ALX Low Level Programming
