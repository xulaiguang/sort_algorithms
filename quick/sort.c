#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

// [lo, hi)
int partition(int *array, int lo, int hi)
{
	int i = lo + 1, j = hi - 1;
	while (i < hi && j > lo) {
		while (less(array, i, lo)) {
			i++;
			if (i == hi)
				break;
		}
		while (less(array, lo, j)) {
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
