#include <stdio.h>
#include <stdlib.h>

void fun(){

  printf("over\n");
}

int main(){
  atexit(fun);
  printf("Process!\n");
  return 0;
}
