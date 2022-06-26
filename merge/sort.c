#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

// insertion sort
void insertion(int *array, int lo, int hi)
{
	for (int i = lo + 1; i < hi; i++) {
		for (int j = i; j > lo; j--) {
			if (compare(array, j, j-1)) 
				swap(array, j, j-1);
			else
				break;
		}
	}
}

// merge [lo, hi)
void merge(int *array, int *aux, int lo, int mid, int hi)
{
	int i = lo, j = mid;
	int k = lo;

	// Without improvement 3, we need to copy array to aux here
	// memcpy(aux + lo, array + lo, (hi - lo) * sizeof(int));

	while (i < mid && j < hi) {
		if (compare(aux, i, j))
			array[k++] = aux[i++];
		else
			array[k++] = aux[j++];
	}

	while (i < mid)
		array[k++] = aux[i++];

	while (j < hi)
		array[k++] = aux[j++];
}

#define CUT_OFF 7

// sort [lo, hi)
void __sort(int *array, int *aux, int lo, int hi)
{
	/* improvement 1: insertion sort subarray which len <= 7 */
	if (hi - lo <= CUT_OFF) {
		insertion(array, lo, hi);
		return;
	}
	int mid = lo + (hi - lo)/2;

	// improvment 3: switch roles of array and aux, avoiding memcpy in merge
	__sort(aux, array, lo, mid);
	__sort(aux, array, mid, hi);

	// improvement 2: left <= right, copy it, avoiding unnecessary compare
	// biggest of left <= smallest of right
	if (compare(aux, mid-1, mid)) {
		memcpy(array + lo, aux + lo, (hi - lo)*sizeof(int));
		return;
	}

	merge(array, aux, lo, mid, hi);
}

void sort(int *array, int size)
{
	int *aux = malloc(size * sizeof(int));
	memcpy(aux, array, size * sizeof(int));

	__sort(array, aux, 0, size);
}
