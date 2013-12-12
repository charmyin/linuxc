#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
void fun(int s){
  printf("I am a signal!%d\n"+s);

}

int main(){
  
  signal(SIGINT,fun);

  while(1){
    printf("Progress on doing!Pid=%d\n",getpid());
    sleep(1);
  }
  return 0;
}
