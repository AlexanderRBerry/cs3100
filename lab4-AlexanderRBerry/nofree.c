#include <stdlib.h>
main(){
    // Unable to free allocated memory
    // Allocated memory not assigned to a pointer
    malloc(1024);
    return 0;
}