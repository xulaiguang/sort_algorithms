#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

void merge(int *array, int *aux, int lo, int mid, int hi)
{
    for (int i = lo; i < hi; i++)
        aux[i] = array[i];
    int i = lo, j = mid, k = lo;
    while (i < mid && j < hi) {
        if (compare(aux, i, j))		array[k++] = aux[i++];
        else						array[k++] = aux[j++];
    }
    while (i < mid)	array[k++] = aux[i++];
    while (j < hi)	array[k++] = aux[j++];
}

#define min(x, y) ((x) <= (y) ? (x) : (y))

void sort(int *array, int len)
{
    int *aux = malloc(len * sizeof(int));
    int sz = 1;
    
    for (int sz = 1; sz < len; sz = sz * 2)
        for (int lo = 0; lo < len-sz; lo = lo + sz*2)
            merge(array, aux, lo, lo + sz, min(lo + sz*2, len));

	free(aux);
}
