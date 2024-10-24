#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

// Initialize the vector with a given memory size

void init(Vector *vector, int memorySize) {
    vector->array = (int*)malloc(memorySize * sizeof(int));
    vector->memorySize = memorySize;
    vector->size = 0;
}


//Free the memory used by the vector and reset its properties

void cleanup(Vector *vector) {
    free(vector->array);
    vector->array = NULL;
    vector->memorySize = 0;
    vector->size = 0;
}

//Print the contents of the vector

void print(Vector *vector) {
    printf("Vector: size=%d, memorySize=%d, elements=[", vector->size, vector->memorySize);
    for (int i = 0; i < vector->size; i++) {
        printf("%d", vector->array[i]);
        if (i < vector->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

//insert a value at a specific location in the vector

int insert(Vector *vector, int location, int value) {
    if (location < 0 || location > vector->size) {
        return 0;  
    }

    if (vector->size == vector->memorySize) {
      
        // Double the size of the array
      
        int newMemorySize = vector->memorySize * 2;
        int *newArray = (int*)malloc(newMemorySize * sizeof(int));
        
        // Copy existing elements
	
        for (int i = 0; i < vector->size; i++) {
            newArray[i] = vector->array[i];
        }

        // Free old array and update vector
	
        free(vector->array);
        vector->array = newArray;
        vector->memorySize = newMemorySize;
    }

    // Shift elements to make room for new value
    
    for (int i = vector->size; i > location; i--) {
        vector->array[i] = vector->array[i - 1];
    }

    // Insert new value
    
    vector->array[location] = value;
    vector->size++;

    return 1;  
}


// Get the value at a specific location in the vector

int get(Vector *vector, int location, int *value) {
    if (location < 0 || location >= vector->size) {
        return 0; 
    }

    *value = vector->array[location];
    return 1; 
}

// Delete an element at a specific location in the vector

int delete(Vector *vector, int location) {
    if (location < 0 || location >= vector->size) {
        return 0;  
    }

    // Shift elements to fill the gap
    
    for (int i = location; i < vector->size - 1; i++) {
        vector->array[i] = vector->array[i + 1];
    }

    vector->size--;
    return 1;  
}
