#include "editorf.h"
#include <iostream>
#include "structures.h"


void append_text(dynamic_array* arr, char* text) {
	for (int i = 0; i < strlen(text); i++) {
		insertItem(arr, text[i]);
	}
}

void start_new_line(dynamic_array* arr) {
	insertItem(arr, '\n');
}

int file_load(dynamic_2d_array* loaded_file, char* file_name) {
	FILE* file = fopen(file_name, "r");

	if (file == NULL) {
		printf("Error opening file");
		return -1;
	}
	else {
		while (fgets(loaded_file->array[loaded_file->size], 256, file) != NULL) {
			dynamic_array* arr_1d;
			arrayInit(&arr_1d);
			
			append_text(arr_1d, loaded_file->array[loaded_file->size]);

			if (loaded_file->array[loaded_file->size][strlen(loaded_file->array[loaded_file->size]) - 1] = '\n') {
				loaded_file->array[loaded_file->size][strlen(loaded_file->array[loaded_file->size]) - 1] = '\0';
			}

			insertItem(loaded_file, arr_1d->array, sizeof(arr_1d->array));
			loaded_file->size++;
		}
		
		fclose(file);
	}
	return 0;
}

int file_save(dynamic_2d_array* arr, int rows, char* file_name) {
	FILE* file = fopen(file_name, "w");
	file = (FILE*)fopen_s(&file, "myfile.txt", "w");
	if (file == NULL) {
		printf("Error opening file\n");
		return -1;
	}
	else {
		for (int i = 0; i < rows; i++) {
			fprintf(file, "%s\n", arr->array[i]);
		}
		fclose(file);
	}
	return 0;
}


void searchSubstring(dynamic_2d_array* arr, char* substring) {
	for (int i = 0; i < arr->size; i++) {
		dynamic_array* line = getItem(arr, i);

		char* str = (char*)malloc((line->size + 1) * sizeof(char));
		for (int j = 0; j < line->size; j++) {
			str[j] = getItem(line, j);
		}
		str[line->size] = '\0';  

		if (strstr(str, substring) != NULL) {
			printf("Substring '%s' found in line %d\n", substring, i);
		}

		free(str);
	}
}


