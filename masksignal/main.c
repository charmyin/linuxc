#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
void fun(){
  printf("I am a signal!\n");
  alarm(4);
}

int main(){
  int sum=0;
  int i;
  sigset_t sigs, sigp;
  sigemptyset(&sigs);
  sigemptyset(&sigp);
  sigaddset(&sigs, SIGINT); 
  sigprocmask(SIG_BLOCK, &sigs, 0);
  for(i=1; i<=10; i++){
    sum+=i;
    sigpending(&sigp);
    if(sigismember(&sigp, SIGINT)){
      printf("SIGINT 在排队!\n");
    }
    sleep(1);
  }
  printf("sum=%d\n", sum);
  sigprocmask(SIG_UNBLOCK, &sigs, 0);
  printf("Over!!\n");
  return 0;
}
