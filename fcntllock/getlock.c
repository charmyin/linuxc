#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd;
  struct flock lk={0};
  int r;
  
  fd=open("a.txt", O_RDWR);
  if(fd==-1){
    printf("::%m\n");
    exit(-1);
  }
  r=fcntl(fd, F_GETLK, &lk);
  if(r==0){
    printf("Get lock successfully!\n");
  }
  if(lk.l_type==F_WRLCK){
    printf("Write lock!\n");
  }
  printf("Started:%d, len:%d\n", lk.l_start, lk.l_len);
  printf("PID : %d\n", lk.l_pid);
  return 0;
}
