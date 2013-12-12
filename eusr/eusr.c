#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
main(){

  int fd;
  char buf[1024];
  int r;
  fd=open("test.txt", O_RDWR);
  if(fd==-1) printf("open error::%m\n"), exit(-1);
  bzero(buf, 1024);
  printf("real user:%d\n", getuid());
  printf("effective user:%d\n", geteuid());
  while((r=read(fd, buf, 1024))>0){
    buf[r]=0;
    printf("%s\n", buf);
  }
  close(fd);
}
