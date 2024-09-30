#include <stdio.h>
#include <stdlib.h>
void allocatememory(int **arr, int size){
 // Allocate memory for an array of 5 integers
    
    *arr = (int*) malloc(size * sizeof(int));
    if (*arr == NULL)
    {
        printf("Memory allocated failed");
        return;
    }
    
    // Initialize and print the array
    for (int i = 0; i < size; i++) {
        (*arr)[i] = i + 1;
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}

void reallocatememory(int **arr,int prevsize, int size){
 *arr = (int*) realloc(*arr, size * sizeof(int));
    
    // Initialize the new elements and print the resized array
    for (int i = prevsize; i < size; i++) {
        (*arr)[i] = i + 1;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}
int main() {
    int size1;
    int size2;
   int *arr = NULL;
   printf("Input first size of the array to allocate: \n");
   scanf("%d", &size1);
    allocatememory(&arr,size1);
    // Resize the array to hold 10 integers
   printf("Input second size of the array to reallocate: \n");
   scanf("%d", &size2);
    reallocatememory(&arr,size1,size2);
    // Free the allocated memory
    free(arr);
    
    return 0;
}
