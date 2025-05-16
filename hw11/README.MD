# CMSC 313 - HW11: hw11translate2Ascii

## Author
Name: Kyle Wu  
Course: CMSC 313  
Assignment: translate2Ascii
---

## Description

This program reads a sequence of raw bytes from an input buffer and converts each byte into two ASCII hexadecimal characters. The converted values are stored in an output buffer and printed to the screen with a space after each byte and a newline at the end.

A subroutine was implemented (to_ascii_hex) to perform the conversion of a full byte into its ASCII hex. A helper subroutine (nibble_to_asci) converts individual 4-bit nibbles.

---

## Example Output

83 6A 88 DE 9A C3 54 9A

---

### Compile

nasm -f elf32 -o hw11translate2Ascii.o hw11translate2Ascii.asm
ld -m elf_i386 -o hw11translate2Ascii hw11translate2Ascii.o

### Run
./hw11translate2Ascii

### Notes for Grader
The source file is located in the hw11/ directory:   hw11/hw11translate2Ascii.asm

Comments are in the program describing logic behind nibble splitting and ASCII conversion.



