; Name: Kyle Wu
; Course: CMSC 313
; Assignment: HW #11
; Description: This program reads raw bytes from inputBuf, converts each to two
;              ASCII hexadecimal characters, stores the result in outputBuf,
;              and prints the full translated output to the screen with a newline.

;              Extra credit: uses a subroutine for byte-to-ASCII hex conversion.

section .data ; For predefined data like your input buffer

inputBuf: db 0x83, 0x6A, 0x88, 0xDE, 0x9A, 0xC3, 0x54, 0x9A ; allocating 8 bytes 

section .bss ; For uninitialized data like output buffer

outputBuf: resb 80 ; Reserve 80 bytes of space for output

section .text
global _start

_start:
    mov esi, inputBuf     ; ESI (source pointer) points to current byte in inputBuf
    mov edi, outputBuf    ; EDI (destination pointer) points to where we write in outputBuf
    mov ecx, 8            ; ECX = how many bytes to process (8 input bytes)

convert_loop:
    mov al, [esi]         ; Load next byte into AL
    call to_ascii_hex     ; Call subroutine to convert and store 2 ASCII chars + space
    inc esi               ; Move to next byte in inputBuf
    loop convert_loop     ; Repeat for all input bytes

    mov byte [edi], 0x0A  ; Add newline character at the end
    inc edi               

    ; Print output buffer to screen
    mov eax, 4            ; syscall number for sys_write
    mov ebx, 1            ; file descriptor 1 = STDOUT
    mov ecx, outputBuf    ; pointer to what we want to print
    mov edx, edi          ; current write position
    sub edx, outputBuf    ; edx = number of bytes to print
    int 0x80              ; call the kernel

    ; Exit the program
    mov eax, 1            ; syscall number for sys_exit
    xor ebx, ebx          ; return code = 0 (success)
    int 0x80              ; call the kernel

; Subroutine: to_ascii_hex
; Converts byte in AL into 2 ASCII hex characters

to_ascii_hex:
    mov bl, al               ; Save original byte 

    ; Example: Byte (8 bits): 10000011 -> 1000 (high nibble) = 0x8
    ;                                  -> 0011 (low nibble)  = 0x3
    ; This subroutine splits the byte into 2 nibbles for hex conversion

    mov ah, al               ; Copy full byte to from al register to AH register
    shr ah, 4                ; shift AH right by 4 bits (high nibble becomes low bits)
    mov al, ah               ; load high nibble into AL for conversion
    call nibble_to_ascii     ; convert high nibble to ASCII
    mov [edi], al            ; Store the result
    inc edi 

    mov al, bl               ; restore original byte into AL
    and al, 0x0F             ; isolate low nibble (lower 4 bits)
    call nibble_to_ascii     ; convert low nibble to ASCII
    mov [edi], al            ; Store ASCII character into outputBuf
    inc edi                  ; Move to next output position

    mov byte [edi], ' '      ; Add space after each byte
    inc edi

    ret

; Subroutine: nibble_to_ascii
; Converts a nibble (0–15) in AL to ASCII

nibble_to_ascii:
    cmp al, 9
    jbe .digit
    add al, 0x37          ; For values 10–15 (A-F)
                          ; 'A' is ASCII 65 -> 10 + 0x37 (55) =  0x41 (65) -> 'A'
    ret
.digit:
    add al, 0x30          ; For values 0–9
                          ; '5' is ASCII 53 -> 5 + 0x30 (48) = 0x35 (53) -> '5'
    ret
