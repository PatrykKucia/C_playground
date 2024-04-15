#include <stdio.h>

typedef union byte
{
    struct
    {
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    }bits;
    unsigned char Value;
}byte;

int main()
{
    union byte test;
    test.bits.bit1 = 1;
    test.bits.bit2 = 1;
    test.bits.bit3 = 1;
    test.bits.bit4 = 1;
    test.bits.bit5 = 1;
    test.bits.bit6 = 1;
    test.bits.bit7 = 1;
    test.bits.bit8 = 1;
    
    printf("%#04hhx\n", test.Value);

    test.Value = 01;

    printf("%#04hhx\n", test.Value);

    printf("individual bits:\n");

    printf("%#hhx\n", test.bits.bit1);
    printf("%#hhx\n", test.bits.bit2);
    printf("%#hhx\n", test.bits.bit3);
    printf("%#hhx\n", test.bits.bit4);
    printf("%#hhx\n", test.bits.bit5);
    printf("%#hhx\n", test.bits.bit6);
    printf("%#hhx\n", test.bits.bit7);
    printf("%#hhx\n", test.bits.bit8);

    return 0;
}
