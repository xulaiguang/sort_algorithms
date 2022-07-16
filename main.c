#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <assert.h>

#include "sort.h"

static int compare_count = 0;
static int swap_count = 0;
static int less_count = 0;

int compare(int *array, int x, int y)
{
	compare_count++;
	if (array[x] <= array[y])
		return 1;
	else
		return 0;
}

int less(int *array, int x, int y)
{
	less_count++;
	if (array[x] < array[y])
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

void print_less_count()
{
	printf("less: %d\n", less_count);
}

void print_swap_count()
{
	printf("swap: %d\n", swap_count);
}

int is_sorted(int *array, int len)
{
	for (int i = 1; i < len; i++) {
		if (array[i-1] > array[i])
			return 0;
	}

	return 1;
}

// generate a random num within [0, hi)
int getrandom(int hi)
{
	static int init = 0;
	if (init == 0) {
		init = 1;
		srand(time(NULL));
	}
	return rand() % hi;
}

int *generate_random_array(int len)
{
	int *array = malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		array[i] = i;
	}

	for (int i = 1; i < len; i++) {
		int r = getrandom(i+1);
		if (r != i) {
			int tmp = array[i];
			array[i] = array[r];
			array[r] = tmp;
		}
	}

	return array;
}

int *generate_random_duplicated_array(int len)
{
	int *array = malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		array[i] = getrandom(len);
	}

	return array;
}

int *generate_all_equal_array(int len)
{
	int *array = malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		array[i] = 1;
	}

	return array;
}


int main(int argc, char *argv[])
{
	struct timespec start, finish;
	unsigned long long i = 0;
	int *array = NULL;
	int len = 10;
	int *random = NULL;
	int ascend[] = { 0,1,2,3,4,5,6,7,8,9 };
	int descend[] = { 9,8,7,6,5,4,3,2,1,0 };

	if (strcmp(argv[1], "random") == 0) {
		len = 100000;
		random = generate_random_array(len);
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

	assert(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start) == 0);
	sort(array, len);
	assert(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish) == 0);
	i = finish.tv_sec - start.tv_sec;
	i *= 1000000000ULL;
	i += finish.tv_nsec - start.tv_nsec;
	i /= 1000ULL;
	printf("consumed %llu.%llums\n", i / 1000ULL, i % 1000ULL);

	assert(is_sorted(array, len));
	print_compare_count();
	print_less_count();
	print_swap_count();
	puts("");
	if (random)
		free(random);
	return 0;
}
