#include <unistd.h>

#define BRAINFUCK_MEMORY_SIZE 30000

int main(int argc, char **argv) {
    if (argc == 1) {
        write(1, "No input is given!\n", 19);
        return 1;
    }
    
    static unsigned char memory[BRAINFUCK_MEMORY_SIZE] = {0};
    unsigned int mem_ptr = 0;
    char loop = 0;
    
    int i = 0;
    while(argv[1][i]) {
        switch (argv[1][i]) {
            case '>':
            ++mem_ptr;
            break;
            case '<':
            --mem_ptr;
            break;
            case '+':
            ++memory[mem_ptr];
            break;
            case '-':
            --memory[mem_ptr];
            break;
            case '.':
            write(1, &memory[mem_ptr], 1);
            break;
            case ',':
            read(0, &memory[mem_ptr], 1);
            break;
            case '[':
            if (memory[mem_ptr] == 0) {
                ++loop;
                while(loop) {
                    ++i;
                    if (argv[1][i] == '[') {
                        ++loop;
                    } else if (argv[1][i] == ']') {
                        --loop;
                    }
                }
            }
            break;
            case ']':
            if (memory[mem_ptr] != 0) {
                ++loop;
                while(loop) {
                    --i;
                    if (argv[1][i] == '[') {
                        --loop;
                    } else if (argv[1][i] == ']') {
                        ++loop;
                    }
                }
            }
            break;
        }
        ++i;
    }
    return 0;
}
