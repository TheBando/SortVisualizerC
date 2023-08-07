#include "sort.h"
#include "visuals.h"

void init_visuals(){
    create();
}
void exit_visuals(){
    clean_up();
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int * array, int low, int high)
{
    int pivot = *(array + high);

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if ( *(array + j) < pivot)
        {
            i++;
            swap (&(*(array + i)), &(*(array + j)));
            //refresh(array);
        }
    }
    swap(&(*(array + i + 1)), &(*(array + high)));
    refresh(array);
    return (i + 1);
}
void quick_sort_with_ptr(int * array, int low, int high)
{
    if (low < high)
    {
        int index = partition(array, low, high);

        quick_sort_with_ptr(array, low, index - 1);
        quick_sort_with_ptr(array, index + 1, high);
    }
}
void quick_sort(int array[], int low, int high)
{

}