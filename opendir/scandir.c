#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int descsort(const struct dirent **a, const struct dirent **b){

  return -(alphasort(a, b));

}

int myfilter(const struct dirent*d){
  if(memcmp(d->d_name, ".", 1)==0){
    return 0;
  }else{
    return -1;
  }
}


int main(){
  struct dirent**d;
  int r;
  int i;
  r=scandir("/home", &d, myfilter, descsort);
  printf("children dir numbers: %d\n",r );
  for(i=0; i<r; i++){
    printf("%d %s \n",i,d[i]->d_name);
  }
  while(*d){
    printf(" %s \n",(*d)->d_name);
    d++;
  }
  return 0;
}
