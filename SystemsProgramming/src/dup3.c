/*** dup3.c ***/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

#define FAILED_POPEN \
        fprintf(stderr, "popen() failed\n"); \
        exit(EXIT_FAILURE);

int main(int argc, char const *argv[]) {

    int    nbytes;
    FILE*  fin;    /* read-end of the pipe */
    FILE*  fout;   /* write-end of the pipe */
    char   buffer[PIPE_BUF];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command1> <command2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fin = popen(argv[1], "r")) == NULL) {
        FAILED_POPEN;
    }

    if ((fout = popen(argv[2], "w")) == NULL) {
        FAILED_POPEN;
    }

    while ((nbytes = read(fileno(fin), buffer, PIPE_BUF)) > 0) {
        write(fileno(fout), buffer, nbytes);
    }
    pclose(fin);
    pclose(fout);

    return 0;
}
