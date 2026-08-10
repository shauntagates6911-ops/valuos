// ValuOS Kernel — pure chaos mode
// This runs after your bootloader jumps to 0x100000

// VGA text buffer
volatile char* vga = (volatile char*)0xB8000;

void valuos_print(const char* msg) {
    int i = 0;
    while (msg[i]) {
        vga[i * 2] = msg[i];     // character
        vga[i * 2 + 1] = 0x0F;   // white on black
        i++;
    }
}

void kernel_main() {
    valuos_print("VALUOS KERNEL ONLINE!!!");

    while (1) {
        // bootup here
    }
}
