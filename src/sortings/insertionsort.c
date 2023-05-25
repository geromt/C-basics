#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * \brief           Sort the elements in array with Insertion Sort
 * \param[in]       array: Array of integers
 * \param[out]      sorted_array : Array that will store the sorted integers
 * \param[in]       length: Number of elements in array
 */
void insertion_sort(int *array, int *sorted_array, int length) {
    int key, i;

    // Copy array
    for (int j=0; j<length; j++) {
        sorted_array[j] = array[j];
    }

    for (int j=1; j<length; j++) {
        key = sorted_array[j];
        i = j - 1;
        while (i >= 0 && sorted_array[i] > key) {
            sorted_array[i+1] = sorted_array[i];
            i--;
        }
        sorted_array[i+1] = key;
    }
}

/**
 * \brief           Fill an array with random numbers from 0 to max
 * \param[out]      array: Array of integers
 * \param[in]       length: Number of random elements to fill the array
 * \param[in]       max: Max integer number in the filled array
 */
void fill_with_random(int *array, int length, int max) {
    srandom(time(NULL));

    for (int i=0; i<length; i++){
        array[i] = random() % max;
    }
}

/**
 * \brief           Print an array of the specified length
 * \param[in]       array: Array of integers
 * \param[in]       length: Length of array
 */
void print_array(int *array, int length) {
    printf("[ ");
    for (int i=0; i<length-1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d ]\n", array[length-1]);
}

int main(int argc, char *argv[]) {
    int length;

    if (argc > 1){
        length = atoi(argv[1]);
    } else {
        length = 10;
    }

    int array[length];
    int sorted_array[length];

    fill_with_random(array, length, 100);

    insertion_sort(array, sorted_array, length);

    print_array(array, length);
    print_array(sorted_array, length);
}