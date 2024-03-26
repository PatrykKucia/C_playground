#include <stdio.h>
#include <string.h>

int main()
{
    typedef struct {

        char brand [20];
        int year;
        int id_type; //1->num vim  2->char vim
        union{
            int id_num;
            char id_char[20];
        }id;
    } vehicle;

    vehicle car;
    strcpy(car.brand, "HONDA");
    car.year = 2004;
    car.id_type = 2;
    strcpy(car.id.id_char, "KS0184IF");
    printf("Brand: %s\n", car.brand);
    printf("Prod. year: %d\n", car.year);
    if(car.id_type==0)
        printf("id: %d",car.id.id_num);
    else
        printf("id: %s",car.id.id_char);
}