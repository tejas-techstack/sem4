#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main() {
  pid_t p1;
  int y = 0;
  p1 = fork();

  if (p1 > 0){
    wait(NULL),
    y--;
    printf("This is parent, pid : %d, y = %d\n", getpid(), y);
  } else if (p1 == 0) {
    y++;
    printf("This is child, pid : %d, ppid : %d, y = %d\n", getpid(), getppid(), y);
    exit(0);
  } else {
    printf("Fork creationg failed");
  }
}
