// Write a program to demonstrate sending a temrination signal to the child.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    printf("In child with id : %d.\n", getpid());
    while (1) {
      printf("Child is running \n");
      sleep(1);
    }
  } else {
    printf("In parent (id : %d)\n", getppid());
    sleep(2);
    printf("Sending terminate to child (id : %d) from parent\n", pid);
    kill(pid, SIGKILL);
    exit(0);
  }
}
