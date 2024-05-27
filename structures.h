#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define INITIAL_SIZE 64 

struct dynamic_array {
	size_t size;
	size_t capacity;
	char* array;
};


void arrayInit(dynamic_array** arr_ptr);
void freeArray(dynamic_array* container);
void insertItem(dynamic_array* arr, char* items, size_t len);	
void updateItem(dynamic_array* container, int i, char item);
void insertItemAtIndex(dynamic_array* arr, int index, char item);
char getItem(dynamic_array* container, int i);
void deleteItem(dynamic_array* container, int item);
void printArray(dynamic_array* container);

#endif


#ifndef DYNAMIC_2D_ARRAY_H
#define DYNAMIC_2D_ARRAY_H

#define INITIAL_SIZE 64 

struct dynamic_2d_array {
	size_t size;
	size_t capacity;
	dynamic_array** array;
};

void arrayInit(dynamic_2d_array* arr);
void insertItem(dynamic_2d_array* arr, dynamic_array* item);
dynamic_array* getItem(dynamic_2d_array* arr, int index);
void updateItem(dynamic_2d_array* arr, int index, char* item, size_t item_size);
void insertItemAtIndex(dynamic_2d_array* arr, int row_index, int col_index, dynamic_array* item);
void deleteItem(dynamic_2d_array* arr, int index);
void freeArray(dynamic_2d_array* arr);

#endif