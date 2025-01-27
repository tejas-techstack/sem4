#include<stdio.h>
#include<unistd.h>

int main(){
  pid_t p1;
  int i = 0, y = 0;
  p1 = fork();

  if(p1>0){
    for(i = 0; i<5; i++){
      sleep(i);
      y = y-1;
      printf("parent, pid: %d, y = %d\n", getpid(), y);
    }
  } else if(p1 == 0) {
    for (i = 0; i<5; i++){
      sleep(i);
      y++;
      printf("child, pid: %d,ppid:%d, y=%d\n", getpid(), getppid(), y);
    }
  } else {
    printf("fork failed or some shi\n");
  }

}
