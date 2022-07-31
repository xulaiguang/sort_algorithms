#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../sort.h"

#define R 256

static unsigned int val_radix(int val, int d)
{
	int mask = 0xff << (d * 8);
	return (val & mask) >> (d * 8);
}

void count_sort(int *array, int *aux, int len, int d)
{
	int count[R+1] = { 0 };

	for (int i = 0; i < len; i++) {
		unsigned int radix = val_radix(array[i], d);
		count[radix + 1]++;
	}

	for (int i = 0; i < R; i++) {
		count[i+1] += count[i];
	}

	for (int i = 0; i < len; i++) {
		unsigned int radix = val_radix(array[i], d);
		aux[count[radix]] = array[i];
		count[radix]++;
	}

	for (int i = 0; i < len; i++) {
		array[i] = aux[i];
	}
}

// Least-Significant-Digit-first sort
void lsd_sort(int *array, int len)
{
	int *aux = malloc(len * sizeof(int));
	assert(aux);

	for (int d = 0; d < sizeof(int) / sizeof(char); d++) {
		count_sort(array, aux, len, d);
	}

	free(aux);
}

void sort(int *array, int len)
{
	lsd_sort(array, len);
}
