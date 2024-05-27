#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"



void arrayInit(dynamic_2d_array* arr) {
    arr->size = 0;
    arr->capacity = INITIAL_SIZE;
    arr->array = (dynamic_array**)calloc(arr->capacity, sizeof(char*));
}

void insertItem(dynamic_2d_array* arr, dynamic_array* item) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        dynamic_array** temp = (dynamic_array**)realloc(arr->array, arr->capacity * sizeof(dynamic_array*));
        if (temp == NULL) {
            printf("Error reallocating memory\n");
            return;
        }
        arr->array = temp;
    }

    arr->array[arr->size] = item;
    arr->size++;
}



dynamic_array* getItem(dynamic_2d_array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        return NULL;
    }
    return arr->array[index];
}


void updateItem(dynamic_2d_array* arr, int index, char* item, size_t item_size) {
    if (index < 0 || index >= arr->size) {
        return;
    }

    dynamic_array* temp = (dynamic_array*)realloc(arr->array[index], item_size * sizeof(char));
    if (temp == NULL) {
        printf("Error reallocating memory\n");
        return;
    }
    arr->array[index] = temp;

    if (arr->array[index] != NULL) {
        memcpy(arr->array[index], item, item_size * sizeof(char));
    }
    else {
        printf("Error: arr->array[index] is NULL\n");
    }
}



void insertItemAtIndex(dynamic_2d_array* arr, int row_index, int col_index, dynamic_array* item) {
    if (row_index < 0 || row_index > arr->size) {
        printf("Index out of bounds\n");
        return;
    }

    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        dynamic_array** temp = (dynamic_array**)realloc(arr->array, arr->capacity * sizeof(dynamic_array*));
        if (temp == NULL) {
            printf("Error reallocating memory\n");
            return;
        }
        arr->array = (dynamic_array**)temp;
    }

    for (int i = arr->size; i > row_index; i--) {
        arr->array[i] = arr->array[i - 1];
    }

    insertItemAtIndex(item, col_index, item->size);
    arr->array[row_index] = (dynamic_array*)item;
    arr->size++;
}






void deleteItem(dynamic_2d_array* arr, int index) {
    if (index < 0 || index >= arr->size) {
        return;
    }

    free(arr->array[index]);

    for (size_t i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }
    arr->size--;
}

void freeArray(dynamic_2d_array* arr) {
    for (size_t i = 0; i < arr->size; i++) {
        free(arr->array[i]);
    }

    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
