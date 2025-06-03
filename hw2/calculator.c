#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_newline(char *s, int maxsize) {
    for (int i = 0; i < maxsize && s[i]; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    const int BUFSIZE = 80;
    char buffer[BUFSIZE];
    FILE *infile = NULL;

    if (argc != 2) {
        fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
        return 1;
    }
    infile = fopen(argv[1], "r");
    if (!infile) {
        fprintf(stderr, "input file %s not found\n", argv[1]);
        return 1;
    }

    long sum = 0;
    char op = '\0';
    int fl = 1;

    while (fgets(buffer, BUFSIZE, infile)) {
        remove_newline(buffer, BUFSIZE);

        if (fl) {
            sum = strtol(buffer, NULL, 10);
            fl = 0;
        } else if (op == '\0') {
            op = buffer[0];
        } else {
            long inp = strtol(buffer, NULL, 10);

            if (op == '+') {
                sum += inp;
            } else if (op == '-') {
                sum -= inp;
            } else if (op == '*') {
                sum *= inp;
            } else if (op == '/') {
                if (inp == 0) {
                    printf("ERROR\n");
                    fclose(infile);
                    return 0;
                }
                sum /= inp;
            } else {
                printf("ERROR\n");
                fclose(infile);
                return 0;
            }
            op = '\0';
        }
    }

    fclose(infile);
    printf("%ld\n", sum);

    return 0;
}
