#include <stdio.h>
#include <unistd.h>

int main(){
  int r=execl("test","", NULL);
  printf("End %d\n", r);
  return 99;
}
