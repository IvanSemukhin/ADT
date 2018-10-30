#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#define UNUSED(expr) do{(void)(expr);} while(0)

#define N_SIZE 45
struct person{
    char name[N_SIZE];
    int age;
};
typedef struct person Item;

typedef struct node{
    Item item;
    struct node * next;
}Node;

typedef Node * List;

void InitList(List * pList);
bool ListIsEmpty(const List * pList);
bool ListIsFull(const List * pList);
unsigned int ListItemCount(const List * pList);
bool AddItem(Item item, List * pList);
void Traverse(const List * pList, void (*pFun)(Item));
void EmptyList(List * pList);

#endif //LIST_H
