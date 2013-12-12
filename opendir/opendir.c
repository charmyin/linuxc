#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
main(){
  DIR *d;
  struct dirent *de;
  
  //open a dir
  d=opendir("../opendir");
  if(d==NULL){
    printf("opendir:%m\n");
    exit(-1);
  }
  //loop read the dir
  while(de=readdir(d)){
    printf("%s, \t %d\n",de->d_name, de->d_type);

  }
  //close the dir
 closedir(d);
}
