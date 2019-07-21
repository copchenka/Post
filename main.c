
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "Post.h"

int main(int argc, char *argv[]) {
    printf("Post Machine simulator.\n"

           "To RUN the program type this line:\n"
           "Post.exe -i intape.txt -q machine.txt -o outtape.txt [-debug]\n"
           "Format of input tape file:\n"
           "....V....\n"
           "001101001\n"
           "Format of state-machine input file:\n"
           "1. 1\n"
           "2. 0\n"
           "3. > \n"
           "4. ? 3;5\n"
           "5. <\n"
           "6. !\n"
           "\n"
           "Flags  '-i', '-q', '-o' must be placed in front of the corresponding file.\n"
           "Next flags  runs debug configuration:\n"
           "'-s' -> next step\n"
           "'-1' -> running to the end\n"
           "'-n p' -> stops the program after p steps\n\n"
           "If program search some mistakes in tape, instructions or somewhere else, you'll see the message in console.\n");
    if (argc < 7) {
        printf("malovato budet");
        return -1;
    }
    FILE *fo;//
    fo = fopen(argv[6], "w");//стирает все, что было до этого в файле
    fclose(fo);
    tape tape1;
    instr *instruction;
    tape1 = readTape(argv[2]);
    instruction = readInstruction(argv[4]);
    int x = 0;
    if (strcmp(argv[7], "-s") == 0) x = 0;
    if (strcmp(argv[7], "-l") == 0) x = -1;
    if (strcmp(argv[7], "-n") == 0) sscanf(argv[8], "%d", &x);
    start(argv[6], tape1, instruction, x);
    free(tape1.values);
    free(instruction);
    return 0;
}
