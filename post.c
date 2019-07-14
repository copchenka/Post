#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

#include "Post.h"

tape readTape(char *fileName) {
	tape tape;
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
				if (line == 2) printf("This simbol can't be in second line: %c\n", c);
				break;
			case 'V':
				if (isHeadFound) printf("I find more than one pointer.\n");
				else if (line == 1) isHeadFound = true;
				else printf("This simbol can't be in second line: %c\n", c);
				break;
			case '0':
				if (line == 2) {
					tape.values = (bool *) realloc(tape.values, (tape.length + 1) * sizeof(bool));
					if (tape.values == NULL) printf("I can't allocate memory for tape.\n");
					tape.values[tape.length] = false;
					tape.length++;
				} else printf("This simbol can't be in first line: %c\n",c);
				break;
			case '1':
				if (line == 2) {
					tape.values = (bool*) realloc(tape.values, (tape.length + 1) * sizeof(bool));
					if (tape.values == NULL) printf("I can't allocate memory.\n");
					tape.values[tape.length] = (c == '1');
					tape.length++;
				} else printf("This simbol can't be in first line: %c\n",c);
				break;
			case '\n':
				line++;
				break;
			default:
				printf("This simbol can't be use in type: %c\n",c);
		}
	}
	if (!isHeadFound) printf("I can't find pointer.");

	fclose(tapeFile);
	return tape;
}

instr* readInstruction(char *filename) {
    instr *operations = (instr *) malloc(sizeof(instr));
    FILE *instrFile = fopen(filename, "r");
    if (instrFile == NULL) printf("I can't open this file2.\n");
    int i = 1;
    int index;
    bool isStopFound = false;
    int f;
struct instr p;
    while ((f = fscanf(instrFile, "%d. %c", &index, &p.instruction)) != EOF) {
        if (f < 2) printf("In line must be more than one element.\n");
        if (index != i) printf("All operations must be numbered in order: 1,2,3,4,...,ect.\n");
        operations = realloc(operations, (i + 1) * sizeof(instr));
        if (operations == NULL) printf("I can't allocate memory for operations.\n");
        switch (p.instruction) {

            case '1':
                if (fgetc(instrFile) != '\n') {
                    fscanf(instrFile, "%d", &p.next);
                    if (p.next <= 0) printf("All numbers of operations must be >= 0.\n");
                } else p.next = i + 1;
                break;
            case '?':
                if (fscanf(instrFile, "%d; %d", &p.next_if_0, &p.next_if_1) < 2)
                    printf("Here(%d. operation's) must be more than one element.\n", i);
                if (p.next_if_1 <= 0 || p.next_if_0 <= 0)
                    printf("All numbers of operations must be >= 0.\n");
                break;
            case '!':
                isStopFound = true;
                break;
            case '<':
                break;
            case '>':
                break;
            case '0':
                break;
            default:
                printf("This symbol(%c, %d) can't be use in operations\n", p.instruction, index);
        }
        fscanf(instrFile, "\n");
        operations[i] = &p;
        i++;
    }
    if (!isStopFound) printf("Instructions haven't stop-symbol.\n");

    fclose(instrFile);
	return operations;
}
void start(tape taper, instr *operations, int i) {
    //i=0-пошаговый
    //>0 определенное количество шагов
    //-1 просто выводим ответ

    int x = 1;
    if (i == 0 || i == -1) {
        do {
            run(taper, operations, x);
            if (i == 0) {
                printinstruction(operations, x);
                printtape(taper);
            }
            x++;
        } while (operations[x]->instruction != '!');
        if (i == -1) printtape(taper);

    }
    if (i > 0) {
        do {
            if (operations[x]->instruction == '!') {
                printf("the number of steps more than you can chose. ");/////////////
                break;
            } else {
                run(taper, operations, x);
                x++;
            }

        } while (x != i || operations[x]->instruction != '!');
    }
}
void run(tape taper, instr *operations, int i) {//выплнение команды под номером i
    if (operations[i]->instruction == '1') {
        taper.values[taper.head] = true;
        taper.head++;
        i = operations[i]->next;
    }
    if (operations[i]->instruction == '0') {
        taper.values[taper.head] = false;
    }
    if (operations[i]->instruction == '>') {//выход за границы
        taper.head++;
    }
    if (operations[i]->instruction == '<') {//выход за границы
        taper.head--;
    }
    if (operations[i]->instruction == '?') {
        if (taper.values[taper.head] == false) i = operations[i]->next_if_0;
        else i = operations[i]->next_if_1;
    }
    if (operations[i]->instruction == '!') {
        printtape(taper);
        printinstruction(operations, i);
    }

}

void printtape(tape result) {
    FILE *fo;
    fo = fopen("output.txt", "w");
    if (fo == NULL) printf("I cant open file for writing");
    int x = 0;
    while (x != result.length) {
        if (x != result.head)fprintf(fo, ".");
        else fprintf(fo, "V");
        x++;
    }
    fprintf(fo, "\n");
    x = 0;
    while (x != result.length) {
        if (result.values[x] == false)fprintf(fo, "0");
        else fprintf(fo, "1");
        x++;
    }
}

int main() {
  tape tape1;
  instr *instruction;
  tape1=readTape("tape.txt");
  instruction= readInstruction("instr.txt");
  printtape(tape1);
	return 0;
}
