#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stdbool.h>

typedef unsigned int UI;
#define MODULE 100
#define N_POS -1

bool isPoly(char str[]);
UI len(const char* str);
void reverse(char* str);
void swap(char* a, char* b);

UI random(void);
void shuffle(char str[]);

void qSort(char* str, int left, int right);
int binarySearch(const char* str, char ch);

bool fuzzy_search(const char* chunk, const char* text);
int find(const char str[], char ch, int pos);
int cmp(const char str1[], const char str2[]);

int nod(int a, int b);

#endif //ALGORITHM_H
