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
void quick_sort(int [], int, int);



#endif