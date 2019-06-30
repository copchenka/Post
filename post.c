
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

 struct tape {
	bool *values;
	int length, head;
} tape;


void readTape(char *fileName) {
	tape.values = (bool*) malloc(sizeof(bool));
	tape.length = 0;
	tape.head = 0;
	FILE *tapeFile = fopen(fileName, "r");
	if (tapeFile == NULL) printf("I can't open this file.\n");
	bool isHeadFound = false;
	int line = 1;
	char c;
	while ((c = fgetc(tapeFile)) != EOF) {
		switch (c) {
			case '.':
				if (!isHeadFound) tape.head++;
				if (line == 2) printf("This simbol can't be in second line/\n");
				break;
			case 'V':
				if (isHeadFound) printf("I find more than one pointer.\n");
				else if (line == 1) isHeadFound = true;
				else printf("This simbol can't be in second line");
				break;
			case '0':
				if (line == 2) {
					tape.values = (bool *) realloc(tape.values, (tape.length + 1) * sizeof(bool));
					if (tape.values == NULL) printf("I can't allocate memory.\n");
					tape.values[tape.length] = false;
					tape.length++;
				} else printf("This simbol can't be in first line.\n");
				break;
			case '1':
				if (line == 2) {
					tape.values = (bool*) realloc(tape.values, (tape.length + 1) * sizeof(bool));
					if (tape.values == NULL) printf("I can't allocate memory.\n");
					tape.values[tape.length] = (c == '1');
					tape.length++;
				} else printf("This simbol can't be in first line.\n");
				break;
			case '\n':
				line++;
				break;
			default:
				printf("This simbol can't be use in type.\n");
		}
	}
	if (!isHeadFound) printf("i can't find pointer.");

	fclose(tapeFile);
}
int main() {
	 readTape("C:\\Users\\BOOK\\CLionProjects\\Post\\tape.txt");
	return 0;
}