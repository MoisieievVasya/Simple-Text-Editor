#include "editorf.h"
#include <iostream>
#include "structures.h"


void append_text(dynamic_array* arr, char* text) {
	size_t textLength = strlen(text);
	for (size_t i = 0; i < textLength; i++) {
		insertItem(arr, &text[i], sizeof(char));
	}
}


void start_new_line(dynamic_array* arr) {
	char item[1] = {'\n',};
	insertItem(arr, item, sizeof('\n'));
}


int file_load(dynamic_2d_array* loaded_file, char* file_name) {
	FILE* file;
	errno_t err = fopen_s(&file, file_name, "r");
	if (err != 0) {
		printf("File not found\n");
		return -1;
	}
	else {
		while (!feof(file)) {
			dynamic_array* line_arr;
			arrayInit(&line_arr);

			int ch;
			while ((ch = fgetc(file)) != EOF && ch != '\n') {
				insertItem(line_arr, (char*)&ch, sizeof(char));
			}

			insertItemAtIndex(line_arr, line_arr->size, '\0');

			insertItem(loaded_file, line_arr); 

			loaded_file->size++;
			
		}
		printf("File loaded successfully\n");
		fclose(file);
	}
	return 0;
}


int file_save(dynamic_2d_array* arr, int rows, char* file_name) {
	FILE* file;
	errno_t err = fopen_s(&file, file_name, "w");

	if (err != 0) {
		printf("Error opening file\n");
		return -1;
	}
	else {
		for (int i = 0; i < rows; i++) {
			if (arr->array != NULL) {
				fprintf(file, "%s\n", arr->array[i]);
			}
		}
		fclose(file);
	}
	return 0;
}


void searchSubstring(dynamic_2d_array* arr, char* substring) {
	for (int i = 0; i < arr->size; i++) {
		dynamic_array* line = (dynamic_array*)getItem(arr, i);

		char* str = (char*)malloc((line->size + 1) * sizeof(char));
		for (int j = 0; j < line->size; j++) {
			str[j] = getItem(line, j);
		}
		str[line->size] = '\0';

		char* found = strstr(str, substring);
		if (found != NULL) {
			int indexInRow = found - str;
			printf("Substring '%s' found in line %d at index %d\n", substring, i, indexInRow);
		}

		free(str);
	}
}



