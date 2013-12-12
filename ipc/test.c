#include <stdio.h>
#include <signal.h>
void handle(int s){
  printf("Hello, signal started~\n");
  sleep(10);
  printf("Hello, signal ended~\n");

}
int main(){
  signal(2,handle);
  printf("%d\n", getpid());
  while(1);
  return 100;
}
