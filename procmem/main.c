#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>
int b=10;

int main(){
  int a=10;
  int *m=malloc(4);
  int *p=mmap(0,4,PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED,0,0);
  *m=10;
  *p=10;


  int r = fork();
  if(r){
    a=100;
    b=100;
    *m=100;
    *p=100;
    printf("parent: a=%d, b=%d, m=%d, mm=%d\n", a,b, *m, *p);
    *p=100;
  }else{
    int j=0;
    while(j<5){
      sleep(1);
      printf("child: a=%d, b=%d, m=%d, mm=%d\n", a,b, *m, *p);
      j++;
    }
  }

  return 0;
}
