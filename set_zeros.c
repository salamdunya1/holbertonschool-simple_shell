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

    for (size_t i = 0; i < size; i++) {
        arr[i] = 0;  
    }
}
