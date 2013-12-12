#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void handle(int s){
  printf("OK!\n");
  sleep(5);
  printf("KO!\n");
}

int main(){
  struct sigaction act={0};
  
  act.sa_handler=handle;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, 12);
  act.sa_flags=0;
  sigaction(SIGUSR1, &act, 0);

  printf("Over!!\n");
  while(1);
  return 0;
}
