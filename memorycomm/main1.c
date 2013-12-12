#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
  int fd[2];
  pipe(fd);
  int fk = fork();
  if(fk){
    //parent
    close(fd[0]);//can only write
    int i=0;
    while(1){
      write(fd[1], "Hello", 5);
      sleep(1);
    }
  }else{
    //child
    char buf[20];
    int r;
    close(fd[1]);//can only read
    while(1){
      r= read(fd[0], buf, 20);
      buf[r]=0;
      printf("Readed %s\n", buf);
    }
    
  }

}
