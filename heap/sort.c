#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../sort.h"

#define root 0

/* max heap, [0, n) */
static inline int parent(int k)
{
	return (k + 1) / 2;
}

static inline int left(int k)
{
	return (k + 1) * 2 - 1;
}

static inline int right(int k)
{
	return left(k) + 1;
}

// [0, n)
static void swim(int *array, int n, int k)
{
	int p = parent(k);
	while (k != root && less(array, p, k)) {
		swap(array, p, k);
		k = p;
	}
}

// [0, n)
static void sink(int *array, int n, int k)
{
	while (left(k) < n) {
		int r = right(k);
		int t = left(k);
		if (r < n && less(array, t, r))
			t = r;

		if (!less(array, k, t))
			break;
		swap(array, k, t);
		k = t;
	}
}

// [0, n)
static void construct(int *array, int n)
{
	for (int k = parent(n - 1); k >= root; k--) {
		sink(array, n, k);
	}
}

void sort(int *array, int n)
{
	construct(array, n);

	int k = n - 1;
	while (k > 0) {
		swap(array, root, k);
		sink(array, k, root);
		k--;
	}
}
