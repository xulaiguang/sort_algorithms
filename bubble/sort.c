#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

void sort(int *array, int size)
{
	for (int i = size; i > 0; i--)
		for (int j = 1; j < i; j++)
			if (compare(array, j, j-1))
				swap(array, j, j-1);
}
