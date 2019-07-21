typedef struct tape {
    bool *values;
    int length, head;
} tape;

typedef struct instr {
    char instruction;
    int next_if_0;
    int next_if_1;
    int next;
} instr;

tape readTape(char *fileName);

instr* readInstruction(char *filename);

void  printtape(char *file, tape result);

tape run(tape taper, instr *operations, int i);

void start(char*output, tape taper, instr *operations, int i);
