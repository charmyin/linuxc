#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <signal.h>
int fd;

void closePipe(int s){
  close(fd);
  exit(-1);
}

main(){
  int i; 
  signal(SIGINT, closePipe);
  mkfifo("my.pipe", 0666);
  fd=open("my.pipe", O_RDWR);
  while(1){
     read(fd,&i, 4);
     printf("%d\n", i);
  }    
}
