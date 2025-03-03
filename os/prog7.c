#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
  printf("Using execvp to execute wel\n");

  char *arg[] = ("wel", NULL);

  if (fork() == 0) {
    execvp("wel", args);
    perror("execvp failed");
    exit(1);
  }

  wait(NULL);
  printf("execvp sample finished \n");
  return 0;
}
