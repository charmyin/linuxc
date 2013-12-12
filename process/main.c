#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  int r;
  printf("%d\n", getpid() );
  r=system("./test");
  //printf("%d\n", r>>8 & 255);
  printf("%d\n", WEXITSTATUS(r));
  return 0;
}
