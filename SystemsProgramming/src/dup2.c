/*** dup2.c ***/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

    int    fd[2];
    int    i;
    pid_t  child1, child2;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command1> <command2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(fd) == -1) {
        perror("pipe call");
        exit(EXIT_FAILURE);
    }

    switch (child1 = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        /* Child process */
        case 0:


        /* Parent process */
        default:
            switch (child2 = fork()) {
                case -1:
                    perror("fork");
                    exit(EXIT_FAILURE);
                case 0:

                default:

                    return 0;
            }
    }
    return 0;
}
