#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_SIZE 45
#define BASE_TEN 10

struct person{
    char name[N_SIZE];
    int age;
    struct person * next;
};

char * s_gets(char* str, int n);

int main(void)
{
    char convert[N_SIZE];
    char input[N_SIZE];
    char * tmpCh;
    struct person * head = NULL;
    struct person * previous = NULL;
    struct person * current = NULL;

    puts("Enter first name or empty string to exit");
    while (s_gets(input, N_SIZE) && input[0] != '\0'){
        current = (struct person*)malloc(sizeof(struct person));

        if (!head)
            head = current;
        else
            previous->next = current;

        current->next = NULL;
        strcpy(current->name, input);
        puts("Enter age");
        fgets(convert, N_SIZE, stdin);
        current->age = strtol(convert, &tmpCh, BASE_TEN);

        puts("Enter next name or empty string to exit");
        previous = current;
    }

    if (!head)
        puts("No data");
    else
        puts("List of data:");

    current = head;
    while (current){
        printf("Name:[%s] age[%d]\n", current->name, current->age);
        current = current->next;
    }

    while (head){
        current = head;
        head = current->next;
        free(current);
    }

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
