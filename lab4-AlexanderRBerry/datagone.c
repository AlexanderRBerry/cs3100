#include <stdlib.h>
#include <stdio.h>
main(){
    // Attempting to access memory that has already been deallocated
    int *ptr;
    ptr = (int *)malloc(100*sizeof(int));
    free(ptr);
    printf("%d\n", ptr[50]);
}