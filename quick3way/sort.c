#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <time.h>

#include "../sort.h"

void __sort(int *array, int lo, int hi)
{
	if (hi <= lo + 1)
		return;

	int i = lo + 1, lt = lo, gt = hi - 1;

	while (i <= gt) {
		if (array[i] < array[lt]) {
			swap(array, i, lt);
			i++;
			lt++;
		} else if (array[i] > array[lt]) {
			swap(array, i, gt);
			gt--;
		} else {
			i++;
		}
	}

	__sort(array, lo, lt);
	__sort(array, gt+1, hi);
}

void sort(int *array, int len)
{
	__sort(array, 0, len);
}
