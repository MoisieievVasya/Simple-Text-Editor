#include <iostream>
#include "editorf.h"
#include "structures.h"

int main() {

	dynamic_array* arr;
	arrayInit(&arr);

	int command; 

	helper();
	
	while (true) {
		printf("Enter your command: \n");
		scanf_s("%d", &command);

		switch (command) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
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








