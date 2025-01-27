#include<stdio.h>
#include<unistd.h>

int main(){
  pid_t p1;
  int y = 10;
  p1 = fork();

  if (p1 > 0) {
    y++;
    printf("This is a parent process. Process Id = %d, y = %d\n",getpid(), y);
  } else if (p1 == 0) {
    y--;
    printf("this is child, process id = %d, parent process id = %d, y = %d\n", getpid(), getppid(), y);
  } else {
    printf("Fork failed");
  }
}
