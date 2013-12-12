#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd;
  struct flock lk;
  //Open a file
  fd=open("a.txt", O_RDWR);
  if(fd==-1) printf(":m\n"), exit(-1);
  //describe the lock
  lk.l_type=F_WRLCK;
  lk.l_whence=SEEK_SET;
  lk.l_start=5;
  lk.l_len=10;
  //add the lock
  int r;
  r=fcntl(fd, F_SETLK,&lk);
  if(r==0) {
    printf("Lock successfully!\n");
  }else{
    printf("Lock failed!\n");
  }
  while(1);
  return 0;
}
