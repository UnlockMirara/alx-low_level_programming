section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0

section .text
    global _start

_start:
    ; Set up stack frame
    mov rbp, rsp
    
    ; Call printf with 'hello' string as the argument
    sub rsp, 8   ; Reserve space for the shadow space (64-bit calling convention)
    mov rsi, hello  ; Load the address of 'hello' into rsi (second argument to printf)
    lea rdi, [format] ; Load the address of 'format' into rdi (first argument to printf)
    call printf

    ; Clean up stack and exit the program
    add rsp, 8   ; Restore the stack pointer to its original position
    xor rdi, rdi ; Set return status to 0 (success)
    call exit
