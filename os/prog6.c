#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
  pid_t p1;
  p1 = fork();

  if (p1 > 0){
    sleep(3);
    printf("in parent\n");
  } else if (p1 == 0){
    printf("In child\n");
    exit(0);
  }

  return 0;
}
