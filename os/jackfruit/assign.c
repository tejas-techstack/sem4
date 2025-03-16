#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_CHILDREN 3

void print_memory_map(pid_t pid) {
    char cmd[50];
    snprintf(cmd, sizeof(cmd), "pmap -x %d", pid);
    system(cmd);
}

int main() {
    pid_t parent_pid = getpid();
    printf("Parent PID: %d\n", parent_pid);

    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();

        if (pid == 0) { // Child process
            printf("   |--Child PID: %d (PPID: %d)\n", getpid(), getppid());

            int *dmem = (int *)malloc(10 * sizeof(int));
            if (dmem == NULL) {
                perror("      |--Memory allocation failed");
                exit(1);
            }
            printf("      |--Dynamic Memory Address: %p\n", dmem);

            // Print the memory map for this child
            print_memory_map(getpid());

            sleep(5); // Simulate some work
            free(dmem);
            printf("      |--Child PID: %d exiting\n", getpid());
            exit(0);
        }
        else if (pid < 0) { // Fork failed
            perror("Fork Failed");
            exit(1);
        }
        else { // Parent process
            // Wait for the current child to finish before forking the next one
            wait(NULL);
        }
    }

    printf("Parent PID: %d finished waiting for all children\n", parent_pid);
    return 0;
}
