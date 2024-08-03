#ifndef __MYOS__VGA_H
#define __MYOS__VGA_H

#include <multiboot.h>
#include <stdint.h>
#include <stddef.h>

union color_info {
    struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };
    uint32_t data;
};
typedef union color_info color_info_t;

void vga_init(const multiboot_info_t *mbi);
void set_color(uint8_t r, uint8_t g, uint8_t b);
void putpixel(size_t x, size_t y, uint32_t color);

void draw_diagonal_line(bool pos, uint32_t color);
void draw_horizontal_line(size_t y, uint32_t color);
void draw_vertical_line(size_t x, uint32_t color);


#endif /* ifndef __MYOS__VGA_H */
