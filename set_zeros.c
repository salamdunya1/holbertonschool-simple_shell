#include "simple_shell.h"

/**
 * set_zeros - set all elements of an array to zero.
 * @arr: the array to be zeroed.
 * @size: the number of elements in the array.
 *
 * This function sets each element in the array `arr` to zero.
 */

void set_zeros(unsigned int *arr, size_t size) {
    if (arr == NULL) {
        return;  
    }
    size_t i;
    i = 0;

   while(i < size) {
        arr[i] = 0;  
        i++;
    }
}
