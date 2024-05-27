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

void insertItem(dynamic_array* container, char item)
{
	if (container->size == container->capacity) {
		char* temp = container->array;
		container->capacity <<= 1;
		container->array = (char*)realloc(container->array, container->capacity * sizeof(char));
		if (!container->array) {
			printf("Out of Memory\n");
			container->array = temp;
			return;
		}
	}
	container->array[container->size++] = item;
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
		arr->array = (char*)realloc(arr->array, arr->capacity * sizeof(char));
		if (arr->array == NULL) {
			printf("Error reallocating memory\n");
			return;
		}
	}

	for (int i = arr->size; i > index; i--) {
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
	printf("Stored text: ");
	for (int i = 0; i < container->size; i++) {
		printf("%d ", container->array[i]);
	}
}

void freeArray(dynamic_array* container)
{
	free(container->array);
	free(container);
	container ->array = NULL;
}
