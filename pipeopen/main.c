#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  char buf[1024];
  FILE *f=popen("ls -l", "r");
  int fd=fileno(f);
  int r;
  printf("====================\n");
  while((r=read(fd, buf, 1024))>0){
    buf[r]=0;
    printf("%d\n",r);
    printf("%s\n", buf);
  }
  printf("====================\n");
  close(fd);
  pclose(f);
}
