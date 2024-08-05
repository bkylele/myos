#include <multiboot.h>
#include <terminal.h>
#include <gdt.h>
#include <interrupts.h>

#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))


void kernel_main([[maybe_unused]] unsigned long magic, unsigned long addr) {
    multiboot_info_t *mbi = (multiboot_info_t *) addr;
    terminal_init(mbi);
    gdt_init();
    idt_init();

    const char str[] = "Hello Operating System :^)";
    terminal_write(str, sizeof(str) - 1);

    for (;;);
}
