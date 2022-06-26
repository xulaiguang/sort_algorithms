#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

void sort(int *array, int size)
{
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (compare(array, j, j-1))
				swap(array, j, j-1);
			else
				break;
												        }
	}
}
