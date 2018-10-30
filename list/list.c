#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node * pNode);

void InitList(List * pList)
{
    *pList = NULL;
}

bool ListIsEmpty(const List * pList)
{
    if(*pList == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List * pList)
{
    UNUSED(pList);
    Node * pNode = (Node*)malloc(sizeof(Node));
    if (pNode == NULL)
        return true;
    else{
        free(pNode);
        return false;
    }
}

unsigned int ListItemCount(const List * pList)
{
    unsigned int count = 0;
    Node * pNode = *pList;
    while (pNode != NULL){
        count++;
        pNode = pNode->next;
    }
    return count;
}

bool AddItem(Item item, List * pList)
{
    Node * pNew;
    Node * head = *pList;

    pNew = (Node*)malloc(sizeof(Node));
    if (pNew == NULL)
        return false;

    CopyToNode(item, pNew);
    pNew->next = NULL;
    if(head == NULL)
        *pList = pNew;
    else{
        while (head->next != NULL)
            head = head->next;
        head->next = pNew;
    }
    return true;
}

void Traverse(const List * pList, void (*pFun)(Item))
{
    Node * head = *pList;
    while (head != NULL){
        pFun(head->item);
        head = head->next;
    }
}

void EmptyList(List * pList)
{
    Node * save;
    while (*pList != NULL){
        save = (*pList)->next;
        free(*pList);
        *pList = save;
    }
}

static void CopyToNode(Item item, Node * pNode)
{
    pNode->item = item;
}
