#include <iostream>
#include "editorf.h"
#include "structures.h"

int main() {

	dynamic_array* buffer;
	arrayInit(&buffer);

	int command; 

	helper();
	
	while (true) {
		printf("Enter your command: \n");
		scanf_s("%d", &command);

		switch (command) {
		case 1:
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {
				insertItem(buffer, ch);
			}
			break;
		case 2:
			start_new_line(buffer);
			break;
		case 3:
			dynamic_2d_array* data;
			arrayInit(data);

			char* file_name;
			scanf_s("%s", file_name);

			file_load(data, file_name);
			break;
		case 4:
			if (data == NULL) {
				printf("No data to save\n");
				break;
			}
			char* file_name_to_save;
			scanf_s("%s", file_name_to_save);
			file_save(data, data->size, file_name);
			break;
		case 5:
			for (int i; i++; i <= data->size) {
				printArray((dynamic_array*)data->array[i]);
			}
			break;
		case 6:
			if (data == NULL) {
				printf("No data to save\n");
				break;
			}
			int row_index;
			int col_index;
			scanf_s("%s", &row_index);
			scanf_s("%s", &col_index);
			insertItemAtIndex(data, row_index, col_index, buffer);
			break;
		case 7:
			if (data == NULL) {
				printf("No data to save\n");
				break;
			}
			char* search_text;
			scanf_s("%s", search_text);
			searchSubstring(data, search_text);
			break;
		case 8:
			printf("\033[2J\033[1;1H");
			break;
		case 0:
			helper();
			break;
		case -1:
			exit(0);
		default:
			printf("The command is not implemented\n");
			printf("If you need help, type 0: \n");
			scanf_s("%d", &command);
			break;	
		}
	} return 0;
}








