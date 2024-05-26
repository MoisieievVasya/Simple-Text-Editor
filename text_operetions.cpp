#include "editorf.h"
#include <iostream>
#include "structures.h"


void append_text(dynamic_array* arr,char* text) {
	
	for (int i = 0; i < strlen(text); i++) {
		insertItem(arr, text[i]);
	}
}

void start_new_line(dynamic_array* arr) {
	insertItem(arr, '\n');
}

int file_load(dynamic_2d_array* loaded_file) {
	FILE* file{};

	if (file == NULL) {
		printf("Error opening file");
		return -1;
	}
	else {
		dynamic_array* arr;
		while(fgets()
		for (int i = 0; i < 100; i++) {
			loaded_file.array[i] = (char*)calloc(100, sizeof(char));
		}
		fclose(file);
	}
	return 0;
}

int file_save() {
	FILE* file;
	file = (FILE*)fopen_s(&file, "myfile.txt", "w");
	if (file != NULL) {
		fputs("Hello, files world!", file);
		fclose(file);
	}
	return 0;
}

