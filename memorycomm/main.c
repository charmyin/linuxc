#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int fd[2];
  int r;
  char buf[20];
  printf("%d\n",getpid());
  r=pipe(fd);
  write(fd[1], "hello", 5);
  write(fd[1], "world", 5);
  r=read(fd[0], buf, 20);
  buf[r]=0;
  printf("%s\n",buf);
  write(fd[1], "louis", 5);
  r=read(fd[0], buf, 20);
  buf[r]=0;
  printf("%s\n",buf);
  while(1);
  return 0;
}

