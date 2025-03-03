// write a program to create a child process that lists all the executing user processes.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
  pid_t p1;
  p1 = fork();

  if (p1 < 0) {
    printf("Fork creation failed.");
  } else {
    if (p1 == 0) {
      printf("In child process.\n");
      char *args[] = {"ps", "-u", NULL};

      execvp("ps", args);
      exit(1);
    } else {
      wait(NULL);
      printf("parent finished\n");
    }
  }
}


