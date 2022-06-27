#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../sort.h"

/*
 * buggy qsort
 * it takes quadratic times if the array has a lot of duplicate keys
 */

int partition(int *array, int lo, int hi)
{
	int i = lo + 1, j = hi - 1;
	while (1) {
		/* doesn't stop on equal keys, buggy! */
		while (array[i] <= array[lo]) {
			i++;
			if (i == hi)
				break;
		}
		while (array[lo] <= array[j]) {
			j--;
			if (j == lo)
				break;
		}

		if (i > j)
			break;

		swap(array, i, j);
		i++;
		j--;
	}

	swap(array, lo, j);
	return j;
}

void __sort(int *array, int lo, int hi)
{
	if (hi <= lo + 1)
		return;

	int j = partition(array, lo, hi);

	__sort(array, lo, j);
	__sort(array, j+1, hi);
}

void sort(int *array, int len)
{
	__sort(array, 0, len);
}
