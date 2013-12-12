#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>

void fun(){
  printf("I am a signal!\n");
  //alarm(4);
}

int main(){
  
  struct itimerval timerval={0};
  timerval.it_value.tv_sec=4;
  timerval.it_interval.tv_sec=1;
  setitimer(ITIMER_REAL, &timerval, 0);
  signal(SIGALRM,fun);
  //int alcount = alarm(7);
  //printf("alarm() method return : %d\n", alcount);
  while(1){
    printf("Progress on doing!Pid=%d\n",getpid());
    //printf("alarm() method return : %d\n", alcount);
    sleep(1);
  }
  return 0;
}
