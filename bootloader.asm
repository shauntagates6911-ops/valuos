; ValuOS bootloader - simple BIOS boot sector
; Assemble with: nasm -f bin bootloader.asm -o bootloader.bin

BITS 16
ORG 0x7C00

start:
    ; Set up segments
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    ; Print message
    mov si, boot_msg
.print_loop:
    lodsb                  ; AL = [SI], SI++
    cmp al, 0
    je .done_print
    mov ah, 0x0E           ; BIOS teletype
    mov bh, 0x00           ; page
    mov bl, 0x07           ; light gray on black
    int 0x10
    jmp .print_loop

.done_print:
.halt:
    cli
    hlt
    jmp .halt

boot_msg:
    db "ValuOS bootloader starting...", 0

; Pad to 510 bytes, then add boot signature 0x55AA
times 510 - ($ - $$) db 0
dw 0xAA55
