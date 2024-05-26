#ifndef DYMANIC_2D_ARRAY_H
#define DYNAMIC_2D_ARRAY_H

#define INITIAL_SIZE 8 

typedef struct {
    size_t size;
    size_t capacity;
    char** array;
} dynamic_2d_array;

void arrayInit(dynamic_2d_array* arr);
void insertItem(dynamic_2d_array* arr, char* item, size_t item_size);
char* getItem(dynamic_2d_array* arr, int index);
void updateItem(dynamic_2d_array* arr, int index, char* item, size_t item_size);
void deleteItem(dynamic_2d_array* arr, int index);
void freeArray(dynamic_2d_array* arr);

#endif


#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define INITIAL_SIZE 8 

typedef struct {
	size_t size;
	size_t capacity;
	char* array;
}dynamic_array;


void arrayInit(dynamic_array** arr_ptr);
void freeArray(dynamic_array* container);
void insertItem(dynamic_array* container, int item);
void updateItem(dynamic_array* container, int i, int item);
char getItem(dynamic_array* container, int i);
void deleteItem(dynamic_array* container, int item);
void printArray(dynamic_array* container);

#endif
