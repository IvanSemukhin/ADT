#include <stdio.h>
#include "algo.h"

int main(void)
{
    char str [] = "MadaM";
    printf("[%s] after reverse = ", str);
    reverse(str);
    printf("[%s]\n", str);

    printf("[%s] is poly = [%d]\n", str, isPoly(str));

    printf("[%s] after shuffle = ", str);
    shuffle(str);
    printf("[%s]\n", str);

    printf("[%s] after sort = ", str);
    qSort(str, 0, (int)len(str)-1);
    printf("[%s]\n", str);

    printf("[%d]\n", fuzzy_search("car", "cartwheel"));
    printf("[%d]\n", fuzzy_search("cartwheel", "cartwheel"));
    printf("[%d]\n", fuzzy_search("lw", "cartwheel"));
    printf("[%d]\n", fuzzy_search("eee", "cartwheel"));
    printf("[%d]\n", fuzzy_search("l", "cartwheel"));
    printf("[%d]\n", fuzzy_search("cl", "cartwheel"));

    printf("nod(923, 598) = [%d]\n", nod(923, 598));

    printf("[%d]\n", binarySearch(str, 'a'));
    printf("[%d]\n", binarySearch(str, 'm'));

    return 0;
}
