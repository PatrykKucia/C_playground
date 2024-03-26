#include <stdio.h>
#include <string.h>

union id {
    int id_num;
    char name[20];
};

void set_id(union id *item,int i)
{
    item->id_num = i;
}

void show_id(union id item)
{
    printf("item number: %d\n",item.id_num);
}

int main(){
    
    union id item; 

    item.id_num = 10;
    show_id(item);
    set_id(&item,20);
    show_id(item);
}