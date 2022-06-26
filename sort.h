#ifndef __SORT_H
#define __SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int compare(int *array, int x, int y);

void swap(int *array, int x, int y);

void print(int *array, int size);

void print_compare_count();

void print_swap_count();

void sort(int *array, int size);


#endif
