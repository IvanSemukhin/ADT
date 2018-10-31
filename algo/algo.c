#include "algo.h"

bool isPoly(char str[])
{
    UI end = len(str)-1;
    UI start = 0;
    while (start < end)
        if (str[start++] != str[end--])
            return false;
    return true;
}

UI len(const char* str)
{
    UI count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

void reverse(char* str)
{
    UI start = 0;
    UI end = len(str)-1;
    while (start < end)
        swap(&str[start++], &str[end--]);
}

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

UI random(void)
{
    static UI next = 1;
    next = next * 1103515245 + 12345;
    return (UI)(next/65536) % (MODULE + 1);
}

void shuffle(char str[])
{
    UI length = len(str);
    for (UI i=0; i < length; i++)
        swap(&str[random() % length], &str[random() % length]);
}

void qSort(char* str, int left, int right)
{
    if(left < right){
        long sup = left;
        for(long i = left; i < right; i++)
            if(str[i] < str[right])
                swap(&str[i], &str[sup++]);
        swap(&str[sup], &str[right]);
        qSort(str, left, sup-1);
        qSort(str, sup+1, right);
    }
}

int binarySearch(const char* str, char ch)
{
    int left = 0;
    int right = len(str)-1;
    while(left <= right){
    int half = (left+right)/2;
    if(str[half] == ch)
        return half;
    else
        str[half] > ch ? (right=half-1) : (left=half+1);
    }
    return N_POS;
}

bool fuzzy_search(const char* chunk, const char* text)
{
    if(len(chunk) > len(text))
        return false;
    if(len(chunk) == len(text))
        return !cmp(chunk, text);
    for(int i=0, index=0;i<len(chunk);i++, index++)
        if(N_POS == (index = find(text, chunk[i], index)))
            return false;
    return true;
}

int find(const char str[], char ch, int pos)
{
    if (len(str) < pos)
        return N_POS;
    while (str[pos] != '\0')
        if (str[pos++] == ch)
            return --pos;
    return N_POS;
}

int cmp(const char str1[], const char str2[])
{
    if (len(str1) == len(str2)){
        UI start = 0;
        while (str1[start] != '\0'){
            if (str1[start] < str2[start])
                return -1;
            if(str1[start] > str2[start])
                return 1;
            start++;
        }
        return 0;
    }
    else
        return len(str1) - len(str2);
}

int nod(int a, int b)
{
    return b ? nod(b, a%b) : a;
}
