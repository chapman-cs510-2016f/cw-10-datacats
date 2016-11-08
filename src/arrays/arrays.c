#include <stdio.h>
#include <stdlib.h>

#include "array.h"


int main(void){
    int array_size = 10;

    // Declare an array of array_size integers in the usual way
    float array[array_size];

    // Allocate a block of array_size integers and assign the address
    // of the beginning of the memory block to the pointer array2
    long double *memblock = malloc(array_size * sizeof(long double));
    /* WARNING: malloc may fail and return a NULL value for the pointer
                Good programming practice mandates checking for such failures.
    */
    if (NULL == memblock) {
      // Print to the "file" of standard error, rather than standard out
      fprintf(stderr, "malloc failed\n");
      // Return a non-successful integer
      return -1;
    }
    set_array(array_size, array, memblock);
    print_array(array_size, array, memblock);

    // explicitly free the block of memory malloc-ed at memblock 
    free(memblock);

    // memory not explicitly freed is automatically freed on function exit
    return 0;
}

void set_array(int array_size, float* array, long double* memblock){
    // iteration index
    int i;

    for (i=0; i < array_size; i++)
    {
        // assign the value i to the ith element 
        array[i] = i;

        // set the value inside the memory address at memblock + (i bytes) to i
        *(memblock+i) = i;
    }
}

void print_array(int array_size, float *array, long double *memblock){
    // iteration index
    int i;

    // constant character array (i.e., a string)
    const char *foo = "Foo bar .";

    // increment three bytes BEYOND the allocated memory (buffer overrun)
    for (i=0; i < (array_size + 3); i++)
    {
        // print the array values in the usual way
        printf("array[%d] : %f\t", i, array[i]);

        // print the values contained in each memory address from memblock on
        printf("*(memblock + %d) : %Lf\t", i, *(memblock+i));

        // print each character in the string
        printf("foo[%d] : %c\t", i, foo[i]);

        // do the same thing, but in pointer notation
        printf("*(foo + %d) : %c\n", i, *(foo+i));
    }

}

