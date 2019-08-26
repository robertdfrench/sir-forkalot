#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv) {
        if (argc < 2) {
                fprintf(stderr, "Need to specify number of forks\n");
                return 1;
        }

        int num_forks = atoi(argv[1]);

        for (int i = 0; i < num_forks; i++) {
                pid_t pid = fork();
                if (pid == 0) {
                        _exit(0);
                } else {
                        int status = 0;
                        waitpid(pid, &status, 0);
                        if (status != 0) {
                                fprintf(stderr, "Child exited uncleanly\n");
                                return 1;
                        }
                }
        }

        return 0;
}
