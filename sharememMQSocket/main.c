#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>
#include <sys/ipc.h>
  int shmid;
  int *p;
//处理卸载函数
void handle(int s){
 if(s==2){
  printf("hello\n");
  //4.卸载共享内存shmdt
  shmdt(p);
  //5.删除共享内存shctl
  shmctl(shmid, IPC_RMID, 0);
  exit(-1);
  }
}
int main(){
  signal(2, handle);
  key_t key;
  //1.创建共享内存shmget
  key=ftok(".",255);
  if(key==-1){
    printf("ftok error: %m\n");
    exit(-1);
  }
  shmid=shmget(key,4,IPC_CREAT|IPC_EXCL|0666 );
  if(shmid==-1){
    printf("get error:%m \n");
    exit(-1);
  }

  //2.挂载共享内存shmat
  p=shmat(shmid, 0, 0);
  if(p==(int *)-1){
    printf("at error:%m\n");
    exit(-1);
  }
  //3.访问共享内存
  int k=0;
  while(1){
    *p=k;
    k++;
    if(k>10){
     break; 
    }
    printf("On noono%d\n", k);
    sleep(1);
  }
  //4.卸载共享内存shmdt
  shmdt(p);
  //5.删除共享内存shctl
  shmctl(shmid, IPC_RMID, 0);
  return 0;
}

