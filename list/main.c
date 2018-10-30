#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_SIZE 45
#define P_MAX 2
#define BASE_TEN 10

struct person{
    char name[N_SIZE];
    int age;
};

char * s_gets(char* str, int n);

int main(void)
{
    struct person info[P_MAX];
    char convert[N_SIZE];
    char * tmpCh;
    int i = 0;
    int j;

    puts("Enter first name or empty string to exit");
    while (i < P_MAX && s_gets(info[i].name, N_SIZE) && info[i].name[0] != '\0'){
        puts("Enter age");
        fgets(convert, N_SIZE, stdin);
        info[i++].age = strtol(convert, &tmpCh, BASE_TEN);
        puts("Enter next name or empty string to exit");
    }

    if (i == 0)
        puts("No data");
    else
        puts("List of data:");

    for (j=0; j<i; j++)
        printf("Name: [%s] Age: [%d]\n", info[j].name, info[j].age);

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
