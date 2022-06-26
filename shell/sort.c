#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

void sort(int *array, int size)
{
	int h = 1;
	while (h < size/3)
		h = h * 3 + 1; // using 3x + 1

	while (h >= 1) {
		// h-sort the array
		for (int i = h; i < size; i++) {
			for (int j = i; j >= h; j -= h) {
				if (compare(array, j, j-h))
					swap(array, j, j-h);
				else
					break;
			}
		}
		h = h / 3;
	}
}
