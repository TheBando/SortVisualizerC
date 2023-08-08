#ifndef SORT_H
#define SORT_H


#include "incl.h"
#include "visuals.h"

/* visual stuff */
void init_visuals();
void exit_visuals();

/*Quick sort stuff*/
void swap(int *, int *);
int partition(int *, int, int);
void quick_sort_with_ptr(int *, int, int);

/*Radix Sort stuff*/
int get_max(int * array, int size);
void counting_sort(int * array, int size, int place);
void radix_sort(int * array, int size);


#endif
