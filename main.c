/* This 'main' file is for testing purposes.
    remember to rename it from 'main' later dude */
#include <time.h>

#include "incl.h"
#include "sort.h"

int main()
{
    time_t t;
    /*random*/
    srand((unsigned) time(&t));
    init_visuals();   
    /* 10 piece array + print the unsorted array */
    int * array = malloc(sizeof *array * 50);
    for (int i = 0; i < 10; i ++)
    {
        *(array + i) = (rand() % 21);
        printf("%d, ", *(array + i));
    }

    printf("\n");
    
    if (pass_info(array, 10) == -1)
    {
        fprintf(stderr, "An error occurred: %s\n", COLOR_ERRO "BAD ARRAY" COLOR_NORM);
        exit(EXIT_FAILURE);
    }

    /* sort */    
    //quick_sort_with_ptr(array, 0, 9);
    radix_sort(array, 10);

    /* print sorted array */
    for (int i = 0; i < 10; i ++)
    {
        printf("%d, ", *(array + i));
    }
    printf("\n");


    sleepMilliseconds(500);
    free(array);
    exit_visuals();
}
