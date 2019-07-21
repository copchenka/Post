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
	if (tapeFile == NULL) 
		 fprintf(stderr, "I can't open this file.\n");
	bool isHeadFound = false;
	int line = 1;
	char c;
	while ((c = fgetc(tapeFile)) != EOF) {
		switch (c) {
			case '.':
				if (!isHeadFound) tape.head++;
				if (line == 2) 
					 fprintf(stderr, "This symbol can't be in second line: %c\n", c);
				break;
			case 'V':
				if (isHeadFound) 
					 fprintf(stderr, "I find more than one pointer.\n");
				else if (line == 1) 
					isHeadFound = true;
				else  
					fprintf(stderr, "This symbol can't be in second line: %c\n", c);
				break;
			case '0':
				if (line == 2) {
					tape.values = (bool *) realloc(tape.values, (tape.length + 1) * sizeof(bool));
					if (tape.values == NULL) 
						fprintf(stderr, "I can't allocate memory for tape.\n");
					tape.values[tape.length] = false;
					tape.length++;
				} else 
					fprintf(stderr, "This symbol can't be in first line: %c\n", c);
				break;
			case '1':
				if (line == 2) {
					tape.values = (bool*) realloc(tape.values, (tape.length + 1) * sizeof(bool));
					if (tape.values == NULL)
						fprintf(stderr, "I can't allocate memory.\n");
					tape.values[tape.length] = (c == '1');
					tape.length++;
				} else
					fprintf(stderr, "This symbol can't be in first line: %c\n", c);
				break;
			case '\n':
				line++;
				break;
			default:
				 fprintf(stderr, "This symbol can't be use in tape: %c\n", c);
		}
	}
	if (!isHeadFound) 
		fprintf(stderr, "I can't find pointer.");

	fclose(tapeFile);
	return tape;
}

instr* readInstruction(char *filename) {
    instr *operations = (instr *) malloc(sizeof(instr));
    FILE *instrFile = fopen(filename, "r");
    if (instrFile == NULL) 
	    fprintf(stderr, "I can't open this file2.\n");
    int i = 1;
    int index;
    bool isStopFound = false;
    int f;
struct instr p;
    while ((f = fscanf(instrFile, "%d. %c", &index, &p.instruction)) != EOF) {
        if (f < 2) 
		 fprintf(stderr, "In line must be more than one element.\n");
        if (index != i)
		fprintf(stderr, "All operations must be numbered in order: 1,2,3,4,...,ect.\n");
        operations = realloc(operations, (i + 1) * sizeof(instr));
        if (operations == NULL) 
		 fprintf(stderr, "I can't allocate memory for operations.\n");
        switch (p.instruction) {

            case '1':
                if (fgetc(instrFile) != '\n') {
                    fscanf(instrFile, "%d", &p.next);
                    if (p.next <= 0) 
			     fprintf(stderr, "All numbers of operations must be >= 0.\n");
                } else p.next = i + 1;
                break;
            case '?':
		p.next = 0;
                if (fscanf(instrFile, "%d; %d", &p.next_if_0, &p.next_if_1) < 2)
                     fprintf(stderr, "Here(%d. operations) must be more than one element.\n", i);
                if (p.next_if_1 <= 0 || p.next_if_0 <= 0)
                    fprintf(stderr, "All numbers of operations must be >= 0.\n");
                break;
            case '!':
		p.next = 0;
                isStopFound = true;
                break;
            case '<':
		p.next = i + 1;
                break;
            case '>':
		p.next = i + 1;
                break;
            case '0':
		p.next = i + 1;
                break;
            default:
                printf("This symbol(%c, %d) can't be use in operations\n", p.instruction, index);
        }
        fscanf(instrFile, "\n");
        operations[i] = &p;
        i++;
    }
    if (!isStopFound) 
	    fprintf(stderr, "Instructions haven't stop-symbol.\n");

    fclose(instrFile);
    return operations;
}
void start(char *output,tape taper, instr *operations, int i) {
    //i=0-пошаговый
    //>0 определенное количество шагов
    //-1 просто выводим ответ
    int d;
    int x = 1;
    if (i == 0 || i == -1) d= 50;
	else d=i;
    while (x != d + 1 && operations[x].instruction != '!') {
	    if (operations[x].instruction != '!') {
            taper = run(taper, operations, x);

            if (i != -1) {
                printinstruction(output, operations, x);
                printtape(output, taper);
            }
            x = operations[x].next;
        } else {
            fprintf(stderr, "The number of steps is out of range.");
            break;
        }
        if (x == d)
            fprintf(stderr, "Program got stuck.");
    }

    if (i == -1) printtape(output, taper);
    else if (operations[x].instruction == '!') {
        printinstruction(output, operations, x);
        printtape(output, taper);
    }
}
tape run(tape taper, instr *operations, int i) {//выплнение команды под номером i
  switch (operations[i].instruction) {
        case '0':
            taper.values[taper.head] = false;
            break;
        case '>':
            taper.head++;
            if (taper.head > taper.length - 1) {
                taper.values = (bool *) realloc(taper.values, (taper.length + 1) * sizeof(bool));
                if (taper.values == NULL)
                    fprintf(stderr, "I can't allocate memory.\n");
                taper.length++;
                taper.values[taper.length - 1] = false;

            }
            break;
        case '<':
            taper.head--;
            if (taper.head < 0) {
                taper.values = (bool *) realloc(taper.values, (taper.length + 1) * sizeof(bool));
                if (taper.values == NULL)
                    fprintf(stderr, "I can't allocate memory.\n");
                taper.length++;
                for (int z = taper.length; z > 0; z--) taper.values[z] = taper.values[z - 1];
                taper.head = 0;
                taper.values[0] = false;
            }
            break;
        case '?':
            if (taper.values[taper.head] == false)
                operations[i].next = operations[i].next_if_0;
            else
                operations[i].next = operations[i].next_if_1;
            break;
        case '1':
            taper.values[taper.head] = true;
            taper.head++;
            if (taper.head > taper.length - 1) {
                taper.values = (bool *) realloc(taper.values, (taper.length + 1) * sizeof(bool));
                if (taper.values == NULL)
                    fprintf(stderr, "I can't allocate memory.\n");
                taper.length++;
                taper.values[taper.length - 1] = false;

            }
            break;
        case '!':
            break;
        default:
            break;
    }
    return taper;
}

void printtape(char *file, tape result) {
    FILE *fo;
    fo = fopen("output.txt", "a");
    if (fo == NULL) 
	    fprintf(stderr, "I can't open file for writing.\n");
    int x = 0;
    while (x != result.length) {
        if (x != result.head)
		fprintf(fo, ".");
        else 
		fprintf(fo, "V");
        x++;
    }
    fprintf(fo, "\n");
    x = 0;
    while (x != result.length) {
        if (result.values[x] == false)
		fprintf(fo, "0");
        else 
		fprintf(fo, "1");
        x++;
    }
    fprintf(fo, "\n");
    fclose(fo);
}

void printinstruction(char *file, instr *result, int i) {
    FILE *fo;//
    fo = fopen(file, "a");
    if (fo == NULL)
        fprintf(stderr, "I cant open file for writing.\n");
    fprintf(fo, "%d. ", i);
    if (result[i].instruction == '1')
        fprintf(fo, "%c %d\n", result[i].instruction, result[i].next);
    else if (result[i].instruction == '?')
        fprintf(fo, "%c %d; %d\n", result[i].instruction, result[i].next_if_0, result[i].next_if_1);
    else
        fprintf(fo, "%c\n", result[i].instruction);
    fclose(fo);
}

