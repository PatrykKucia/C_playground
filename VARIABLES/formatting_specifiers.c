#include <stdio.h>

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");

    int a, b, c;

    // between %i and %d specifier
    printf("Enter value of a in decimal format:");
    scanf("%d", &a);
 
    printf("Enter value of b in octal format: ");
    scanf("%i", &b);
 
    printf("Enter value of c in hexadecimal format: ");
    scanf("%i", &c);
 
    printf("a = %i, b = %i, c = %i", a, b, c);
 
    return 0;
}