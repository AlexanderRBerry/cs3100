#include <stdlib.h>
main(){
    // Outof bounds access
    int *ptr;
    ptr = (int*)malloc(100*sizeof(int));
    ptr[100] = 0;
}