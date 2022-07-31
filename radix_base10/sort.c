#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "../sort.h"

#define R 10

static unsigned int val_radix(int val, int exp)
{
	
	int ret = (val % exp) / (exp / 10);
	assert(ret >= 0 && ret < 10);
	return ret;
}

static int find_max(int *array, int len)
{
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (max < array[i])
			max = array[i];
	}

	return max;
}

void count_sort(int *array, int *aux, int len, int exp)
{
	int count[R+1] = { 0 };

	for (int i = 0; i < len; i++) {
		unsigned int radix = val_radix(array[i], exp);
		count[radix + 1]++;
	}

	for (int i = 0; i < R; i++) {
		count[i+1] += count[i];
	}

	for (int i = 0; i < len; i++) {
		unsigned int radix = val_radix(array[i], exp);
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

	int max = find_max(array, len);

	for (int exp = 10; max * 10 / exp != 0; exp = exp * 10) {
		count_sort(array, aux, len, exp);
	}

	free(aux);
}

void sort(int *array, int len)
{
	lsd_sort(array, len);
}
