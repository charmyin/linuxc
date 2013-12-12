#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void deal(int s){
      int status;
      wait(&status);
      printf("Recycled child!!pid=%d\n", WEXITSTATUS(status));
}

int main(){
  int r;
  printf("%d\n", getpid() );
  int t=fork();
  if(t==0){
   // while(1){
      printf("child!!\n");
      sleep(10);
      printf("child end!!\n");
      exit(88);
    //}
  }else{
    //while(1){
      signal(17,deal);
      printf("parent start!\n");
      while(1){
        sleep(1);
        printf("parent on loading~\n");
      }
      printf("parent end!\n");
   // }
  }



  return 0;
}
