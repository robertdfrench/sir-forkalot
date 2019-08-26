#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	int status = 0;

        for (int i = 0; i < 10000; i++) {
                pid_t pid = fork();
                if (pid == 0) _exit(0);

		waitpid(pid, &status, 0);
		if (status != 0) return status; // Child exited uncleanly
        }

        return 0;
}
