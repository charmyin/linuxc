#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(){
  int r;
  int count=0;
  int pid=4598;
  while(1){
    count++;
    r= kill(4598, 2);
    sleep(2);
    if(count==5){
      break;
    }
  }
  kill(4598, 9);
  return 0;
}
