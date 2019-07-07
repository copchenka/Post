struct tape {
    bool *values;
    int length, head;
} tape;

typedef struct instr {
    char instruction;
    int next_if_0;
    int next_if_1;
    int next;
} *instr;

void readTape(char *fileName);

void readInstruction(char *filename);