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


/***********************************************************/
int get_max(int * array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i ++)
    {
        if (*(array + i) > max)
            max = *(array + i);

    }
    return max;
}

void counting_sort(int * array, int size, int place)
{
    int * out = malloc(sizeof *out * size);
    int max = (*(array) / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((*(array + i) / place) % 10) > max)
            max = *(array + i);
    }
    int * count = malloc(sizeof *count * (max + 1));

    for (int i = 0; i < max; i++)
    {
        *(count + i) = 0;
    }
    for (int i = 0; i < size; i++)
    {
        *(count + ((*(array + i) / place) % 10)) += 1;
    }
    for (int i = 1; i < 10; i++)
    {
        *(count + i) += *(count + (i - 1));
    }
    for (int i = size - 1; i >= 0; i--)
    {
        *(out + ((*(count + (*(array +i) / place) % 10) -1 ))) = *(array + i);
        *(count + ((*(array + i) / place) % 10)) -= 1;
    }
    for (int i = 0; i < size; i++)
    {
        *(array + i) = *(out + i);
    }
}

void radix_sort(int * array, int size)
{
    int max = get_max(array, size);
    refresh(array);
    for (int place = 1; max / place > 0; place *= 10)
    {
        counting_sort(array, size, place);
        refresh(array);
    }
}
