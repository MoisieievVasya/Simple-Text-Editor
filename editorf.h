#ifndef EDITORF_H	
#define EDITORF_H

#include "structures.h"

void helper();
void append_text(dynamic_array* arr, char* text);
void start_new_line(dynamic_array* arr); 
int file_load(dynamic_2d_array* loaded_file, char* file_name);
int file_save(dynamic_2d_array* data, int rows, char* file_name);
void searchSubstring(dynamic_2d_array* arr, char* substring);

#endif

