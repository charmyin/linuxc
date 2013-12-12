#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/socket.h>
int fd;

void closePipe(int s){
  close(fd);  
  unlink("my.pipe");
  exit(-1);
}


main(){
  int i=0; 
  signal(SIGINT, closePipe);
  mkfifo("my.pipe", 0666);
  fd=open("my.pipe", O_RDWR);
  shutdown(fd, SHUT_WR);
  while(1){
      sleep(1);
      write(fd, &i, 4);
      i++;
  }
}
