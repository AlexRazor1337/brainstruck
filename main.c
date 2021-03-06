#include <stdlib.h>
#include <string.h>

#define BRAINFUCK_MEMORY_SIZE 30000

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("No input is given!\n");
        exit(EXIT_FAILURE);
    }
    
    unsigned char memory[BRAINFUCK_MEMORY_SIZE] = {0};
    unsigned int mem_ptr = 0;
    char loop = 0;
    
    for (int i = 0; i < strlen(argv[1]); ++i) {
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
            printf("%c", memory[mem_ptr]);
            break;
            case ',':
            scanf("%c", &memory[mem_ptr]);
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
            } else continue;
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
            } else continue;
            break;
            default:
            continue;
        }
    }
    return 0;
}
