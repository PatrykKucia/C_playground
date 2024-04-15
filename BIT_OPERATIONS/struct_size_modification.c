// C program to demonstrate use of Bit-fields
#include <stdio.h>
 
// Space optimized representation of the date
struct date_m {
    // d has value between 0 and 31, so 5 bits
    // are sufficient
    int d : 6;
 
    // m has value between 0 and 15, so 4 bits
    // are sufficient
    int m : 5;
 
    int y;
};
 

struct date {
    unsigned int d;
    unsigned int m;
    unsigned int y;
};

int main()
{
    printf("Size of date is %lu bytes\n",
    sizeof(struct date));
    struct date dt = { 31, 12, 2014 };
    printf("Date is %d/%d/%d\n", dt.d, dt.m, dt.y);

    printf("Size of date is %lu bytes\n",
    sizeof(struct date_m));
    struct date_m dt_m = { 31, 12, 2014 };
    printf("Date is %d/%d/%d\n", dt_m.d, dt_m.m, dt_m.y);

    return 0;
}