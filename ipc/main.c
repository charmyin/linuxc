#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
  int i;
  int fd;
  fd=open("tmp", O_RDWR|O_CREAT, 0666);
  ftruncate(fd,4);
  int *p;
  p=mmap(0, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd,0);
  i=0;
  printf("OKOK1\n");
  while(1){
    printf("OKOK--%d\n", *p);
    sleep(1);
    *p=i;
    printf("OKOK2\n");
    i++;
    printf("Writed:%d\n", i);
  }  
  close(fd);
  return 0;
}
