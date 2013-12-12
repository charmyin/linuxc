#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(){
  int fd=open("tmp", O_RDWR);
  int *p=mmap(0, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
  while(1){
    sleep(1);
    printf("%d\n", *p);
  }  
  close(fd);
  return 0;
}
