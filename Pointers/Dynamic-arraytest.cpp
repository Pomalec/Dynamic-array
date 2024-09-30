#include <stdio.h>
#include <stdlib.h>

// Dynamic array structure
typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} DynamicArray;

// Initializing the dynamic array
DynamicArray* initArray(size_t initialCapacity) {
    DynamicArray* dynArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    dynArray->array = (int*)malloc(initialCapacity * sizeof(int));
    dynArray->size = 0;
    dynArray->capacity = initialCapacity;
    return dynArray;
}

// Adding element to the dynamic array
void pushBack(DynamicArray *dynArray, int value) {
    if (dynArray->size == dynArray->capacity) {
        // Resize array (double the capacity)
        dynArray->capacity *= 2;
        dynArray->array = (int*)realloc(dynArray->array, dynArray->capacity * sizeof(int));
    }
    dynArray->array[dynArray->size++] = value;
}

// Remove last element (pop)
void popBack(DynamicArray *dynArray) {
    if (dynArray->size > 0) {
        dynArray->size--;
    }
}

// Get element by index
int get(DynamicArray *dynArray, size_t index) {
    if (index >= dynArray->size) {
        printf("Index out of bounds\n");
        return -1; // Error code
    }
    return dynArray->array[index];
}

// Free the array
void freeArray(DynamicArray *dynArray) {
    free(dynArray->array);
    free(dynArray);
}

// Main function for testing
int main() {
    int size, element, index;
    printf("Input size of the dynamic array: \n");
   scanf("%d", &size);
    DynamicArray *arr = initArray(size);
     for (int i = 0; i < size; i++) {
        printf("Input element to add to the array: \n");
   scanf("%d", &element);
         pushBack(arr, element);
    }
   printf("Input index to get element of the array: \n");
   scanf("%d", &index);
    printf("Element at the requested index: %d\n", get(arr, index));
    
    popBack(arr);
    printf("Element at index 1 after pop: %d\n", get(arr, 1));
    
    freeArray(arr);
    return 0;
}
