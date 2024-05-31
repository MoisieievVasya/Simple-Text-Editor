#include <iostream>
#include "structures.h"
#include "editorf.h"
#include "donut.h"


int main() {

	dynamic_array* buffer = nullptr;
	arrayInit(&buffer);

	int command;

	float A = 0;
	float B = 0;

	helper();

	dynamic_2d_array* data = nullptr;
	char* file_name = nullptr;
	char* file_name_to_save = nullptr;
	char* search_text = nullptr;


	while (true) {
		printf("Enter your command: \n");
		scanf_s("%d", &command);
		getchar();

		switch (command) {
		case 1: {
			printf("Enter the text: \n");

			char ch;
			char* ptr = &ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {
				insertItem(buffer, ptr, sizeof(char));
			}
			char item[1] = { '\0' };
			insertItem(buffer, item, sizeof(char));
		}
			  break;
		case 2:
			start_new_line(buffer);
			printf("New line was created\n");
			break;
		case 3:
			if (data != NULL) {
				freeArray(data);
			}
			if (data == NULL) {
				data = (dynamic_2d_array*)malloc(sizeof(dynamic_2d_array));
				arrayInit(data);
			}

			file_name = new char[256];
			printf("Enter the name of the file: \n");
			scanf_s("%s", file_name, 256);

			file_load(data, file_name);
			break;
		case 4:

			file_name_to_save = new char[256];
			printf("Enter the name of the file: \n");
			scanf_s("%s", file_name_to_save, 256);

			if (buffer == NULL) {
				printf("No data to save\n");
				break;
			}

			if (buffer != NULL) {
				if (data == NULL) {
					data = (dynamic_2d_array*)malloc(sizeof(dynamic_2d_array));
					arrayInit(data);
				}
				insertItem(data, buffer);
			}
			
			if (data != NULL) {
				for (int i = 0; i < data->size; i++) {
					file_save(data, static_cast<int>(data->array[i]->size), file_name_to_save);
				}
			}
			
			break;
		case 5:
			if (data == NULL && buffer == NULL) {
				printf("No data to print\n");
				break;
			}
			else if (data == NULL && buffer != NULL) {
				printArray(buffer);
				break;
			}
			else if (data != NULL && buffer == NULL) {
				printf("Stored text: \n");
				for (int i = 0; i < data->size; i++) {
					printArray((dynamic_array*)data->array[i]);
				}
				break;
			}	
			else {
				printf("Stored text: \n");
				for (int i = 0; i < data->size; i++) {
					printArray((dynamic_array*)data->array[i]);
				}
				printArray(buffer);
				break;
			}
		case 6:
		{
			if (data == NULL && buffer == NULL) {
				printf("No data to insert\n");
				break;
			}
			else if (data == NULL && buffer != NULL) {
				printf("Enter the index of the row: \n");
				int row_index;
				scanf_s("%d", &row_index);
				
			}
			else if (data != NULL && buffer != NULL) {
				insertItem(data, buffer);
				dynamic_array* line_to_insert = nullptr;
				arrayInit(&line_to_insert);
				int row_index, col_index;
				printf("Enter the index of the row: \n");
				scanf_s("%d", &row_index);
				printf("Enter the index of the symbol: \n");
				scanf_s("%d", &col_index);
				insertItemAtIndex(data, row_index, col_index, buffer);
				break;
			}
			
		}
		case 7:
			if (data == NULL && buffer == NULL) {
				printf("No data to search\n");
				break;
			}
			else if (data == NULL && buffer != NULL) {
				printf("Enter the text to search trouhgt data: \n");

				data = (dynamic_2d_array*)malloc(sizeof(dynamic_2d_array));
				arrayInit(data);

				insertItem(data, buffer);
				search_text = new char[256];
				scanf_s("%s", search_text, 256);
				searchSubstring(data, search_text);
				break;
			}
			else if (data != NULL && buffer == NULL) {
				printf("Enter the text to search trouhgt data: \n");
				search_text = new char[256];
				scanf_s("%s", search_text, 256);
				searchSubstring(data, search_text);
				break;
			}
			insertItem(data, buffer);
			search_text = new char[256];  
			scanf_s("%s", search_text, 256);  
			searchSubstring(data, search_text);
			break;
		case 8:
			printf("\033[2J\033[1;1H");
			break;
		case 9: 
			while(1) {
				render_frame(A, B);
				A += 0.07f;
				B += 0.035f;
			}
			break;
		case 0:
			helper();
			break;
		case -1:
			exit(0);
		default:
			printf("The command is not implemented\n");
			break;	
		}
	} return 0;
}








