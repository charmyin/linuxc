#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void h(int s){
  printf("Unsuspend Signal happened~ %d\n",s);
}

int main(){
  sigset_t sigs;
  signal(SIGUSR1,h);
  signal(SIGWINCH,h);
  sigemptyset(&sigs);
  sigaddset(&sigs, 2);
  printf("Suspend started\n");
  sigsuspend(&sigs);
  printf("Suspend ended\n");
  return 0;
}
