#include <stdlib.h>
main(){
    // Freeing only part of allocated memory
    int *ptr;
    ptr = (int*)malloc(100*sizeof(int));
    free(ptr+50);
}