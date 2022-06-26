#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "sort.h"

static int compare_count = 0;
static int swap_count = 0;

int compare(int *array, int x, int y)
{
	compare_count++;
	if (array[x] <= array[y])
		return 1;
	else
		return 0;
}

void swap(int *array, int x, int y)
{
	int tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
	swap_count++;
}

void print(int *array, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	puts("");
}

void print_compare_count()
{
	printf("compare: %d\n", compare_count);
}

void print_swap_count()
{
	printf("swap: %d\n", swap_count);
}

int main(int argc, char *argv[])
{
	int *array;
	int random[] = { 1,4,5,6,7,3,2,9,8,0 };
	int ascend[] = { 0,1,2,3,4,5,6,7,8,9 };
	int descend[] = { 9,8,7,6,5,4,3,2,1,0 };
	if (strcmp(argv[1], "random") == 0) {
		array = random;
		printf("------- random array -------\n");
	} else if (strcmp(argv[1], "ascend") == 0) {
		array = ascend;
		printf("------- ascend array -------\n");
	} else if (strcmp(argv[1], "descend") == 0) {
		array = descend;
		printf("------- descend array -------\n");
	} else {
		return -1;
	}
	sort(array, 10);
	print(array, 10);
	print_compare_count();
	print_swap_count();
	puts("");
	return 0;
}
