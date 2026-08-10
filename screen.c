// ValuOS Screen Driver
// Writes characters anywhere on the VGA text buffer

#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

volatile unsigned char* vga = (unsigned char*)VGA_MEMORY;

void screen_put(char c, int x, int y) {
    int index = (y * VGA_WIDTH + x) * 2;
    vga[index] = c;       // character
    vga[index + 1] = 0x0F; // white on black
}

void screen_write(const char* msg, int row) {
    int i = 0;
    while (msg[i]) {
        screen_put(msg[i], i, row);
        i++;
    }
}
