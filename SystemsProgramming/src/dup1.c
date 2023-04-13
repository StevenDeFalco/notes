/*** dup1.c ***/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

    int  fd[2];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command1> <command2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(fd) == -1) {
        perror("pipe call");
        exit(EXIT_FAILURE);
    }

    switch (fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        /* Child process */
        case 0:


        /* Parent process */
        default:

    }
    return 0;
}
