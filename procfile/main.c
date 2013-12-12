#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
int main(){
  int fd=open("test.txt", O_RDWR);
  //int f=fork();
  if(fork()){
    char buf[1024]={0};
    read(fd, buf, 1024);
    printf("Parent : %s\n", buf);
  }else{
    char buf[1024]={0};
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, 1024);
    printf("Child : %s\n", buf);
  }
  close(fd);
  return 0;
}
