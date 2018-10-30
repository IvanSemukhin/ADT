#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define BASE_TEN 10

void showPerson(Item item);
char * s_gets(char* str, int n);

int main(void)
{
    char convert[N_SIZE];
    char * tmpCh;

    List info;
    Item input;
    InitList(&info);

    if (ListIsFull(&info)){
        puts("No empty memory!");
        exit(1);
    }

    puts("Enter first name or empty string to exit");
    while (s_gets(input.name, N_SIZE) && input.name[0] != '\0'){
        puts("Enter age");
        fgets(convert, N_SIZE, stdin);
        input.age = strtol(convert, &tmpCh, BASE_TEN);

        if (AddItem(input, &info) == false){
            puts("No available memory!");
            break;
        }

        if (ListIsFull(&info)){
            puts("List is full!");
            break;
        }

        puts("Enter next name or empty string to exit");
    }

    if (ListIsEmpty(&info))
        puts("No data");
    else
        puts("List of data:");
    Traverse(&info, showPerson);
    printf("Entered [%d] data\n", ListItemCount(&info));
    EmptyList(&info);

    puts("Program end.");
    return 0;
}

char * s_gets(char* str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val){
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void showPerson(Item item)
{
    printf("Name:[%s] age:[%d]\n", item.name, item.age);
}
