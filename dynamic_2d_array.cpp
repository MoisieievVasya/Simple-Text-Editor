#include <stdlib.h>
#include <string.h>
#include "structures.h"



void arrayInit(dynamic_2d_array* arr) {
    arr->size = 0;
    arr->capacity = INITIAL_SIZE;
    arr->array = (char**)calloc(arr->capacity, sizeof(char*));
}

void insertItem(dynamic_2d_array* arr, char* item, size_t item_size) {
    if (arr->size == arr->capacity) {
        // The array is full, so we need to allocate more memory
        arr->capacity *= 2;
        arr->array = (char**)realloc(arr->array, arr->capacity * sizeof(char*));
    }

    // Allocate memory for the new item and copy it into the array
    arr->array[arr->size] = (char*)calloc(item_size, sizeof(char));
    memcpy(arr->array[arr->size], item, item_size * sizeof(char));
    arr->size++;
}

char* getItem(dynamic_2d_array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        // Invalid index
        return NULL;
    }
    return arr->array[index];
}

void updateItem(dynamic_2d_array* arr, int index, char* item, size_t item_size) {
    if (index < 0 || index >= arr->size) {
        // Invalid index
        return;
    }

    // Reallocate memory for the item and copy the new item into the array
    arr->array[index] = (char*)realloc(arr->array[index], item_size * sizeof(char));
    memcpy(arr->array[index], item, item_size * sizeof(char));
}

void deleteItem(dynamic_2d_array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        // Invalid index
        return;
    }

    // Free the memory of the item to be deleted
    free(arr->array[index]);

    // Shift the remaining items down
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }
    arr->size--;
}

void freeArray(dynamic_2d_array* arr) {
    // Free the memory of each item
    for (size_t i = 0; i < arr->size; i++) {
        free(arr->array[i]);
    }

    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
