#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

void sort(int *array, int size)
{
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i+1; j < size; j++)
			if (compare(array, j, min))
				min = j;
		if (min != i)
			swap(array, min, i);
	}
}
