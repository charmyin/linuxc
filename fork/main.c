#include <stdio.h>
#include <unistd.h>

int main(){
  printf("Before creating process~\n");
  int pid=fork();
  if(pid==0){
    printf("child pid : %d\n", getpid());
    //printf("After creating process child pid : %d\n", pid);
  }
  else{
    printf("parent pid : %d\n", getpid());
    printf("After creating process child pid: %d\n", pid);
  }
}
