#include "printf.h"

extern int __bss_start__;
extern int __bss_end__;

extern void main();

// Zeroes out the BSS before calling main.
void _cstart() {
    int *bss = &__bss_start__;
    int *bss_end = &__bss_end__;

    printf_init();
    printf("bss_end=%08x\n", (unsigned)bss_end);

    while (bss < bss_end) {
        *bss++ = 0;
    }

    main();
}
