#include "structures.h"
#include <iostream>


void arrayInit(dynamic_array** arr_ptr)
{
	dynamic_array* container;
	container = (dynamic_array*)calloc(1,sizeof(dynamic_array));
	if (!container) {
		printf("Memory Allocation Failed\n");
		exit(0);
	}

	container->size = 0;
	container->capacity = INITIAL_SIZE;
	container->array = (char*)calloc(INITIAL_SIZE, sizeof(char));
	if (!container->array) {
		printf("Memory Allocation Failed\n");
		exit(0);
	}

	*arr_ptr = container;
}

void insertItem(dynamic_array* arr, char* items, size_t len) {
	if (arr == nullptr) {
		printf("Array is null\n");
		return;
	}
	if (arr->size + len > arr->capacity) {
		while (arr->size + len > arr->capacity) {
			arr->capacity *= 2;
		}
		char* temp = (char*)realloc(arr->array, arr->capacity * sizeof(char));
		if (temp == NULL) {
			printf("Error reallocating memory\n");
			return;
		}
		arr->array = temp;
	}

	memcpy(arr->array + arr->size, items, len);
	arr->size += len;
}






char getItem(dynamic_array* container, int index)
{
	if (index >= container->size) {
		printf("Index Out of Bounds\n");
		return -1;
	}
	return container->array[index];
}

void updateItem(dynamic_array* container, int index, char item)
{
	if (index >= container->size) {
		printf("Index Out of Bounds\n");
		return;
	}
	container->array[index] = item;
}

void insertItemAtIndex(dynamic_array* arr, int index, char item) {
	if (index < 0 || index > arr->size) {
		printf("Index out of bounds\n");
		return;
	}

	if (arr->size == arr->capacity) {
		arr->capacity *= 2;
		char* temp = (char*)realloc(arr->array, arr->capacity * sizeof(char));
		if (temp == NULL) {
			printf("Error reallocating memory\n");
			return;
		}
		arr->array = temp;
	}

	for (int i = arr->size; i > index; --i) {
		arr->array[i] = arr->array[i - 1];
	}

	arr->array[index] = item;
	arr->size++;
}



void deleteItem(dynamic_array* container, int index)
{
	if (index >= container->size) {
		printf("Index Out of Bounds\n");
		return;
	}

	for (int i = index; i < container->size; i++) {
		container->array[i] = container->array[i + 1];
	}
	container->size--;
}

void printArray(dynamic_array* container)
{
    if (container == NULL) {
        return;
    }

    
    for (int i = 0; i < container->size; i++) {
        if (container->array[i] != NULL) {
            printf("%c", container->array[i]);
        }
    }
	printf("\n");
}


void freeArray(dynamic_array* container)
{
	if (container == NULL) {
		printf("Container is already NULL\n");
		return;
	}

	free(container->array);
	free(container);
	container = NULL;
}

