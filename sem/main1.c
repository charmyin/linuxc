#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun{
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  struct seminfo *__buf;
};

int main(){
  key_t key;
  int semid;
  union semun v;
  //创建信号量
  key=ftok(".", 99);
  if(key==-1){
    printf("ftok error : %m\n");
    exit(-1);
  }
  //semid=semget(key, 1, IPC_CREAT|IPC_EXCL|0666);
  semid=semget(key, 1, 0);
  if(semid==-1){
    printf("get error : %m\n");
    exit(-1);
  }
  printf("semid : %d\n", semid);
  //初始化信号量
  v.val=2;
  int r;
  printf("hello2\n");
  r=semctl(semid, 0, SETVAL, v);
  if(r==-1){
    printf("初始化失败:%m");  
    exit(-1);
  }
  printf("hello2\n");
  //对信号量进行阻塞操作
  struct sembuf op[1];
  op[0].sem_num=0;//信号量的下标
  op[0].sem_op=1;//信号量操作单位与类型
  op[0].sem_flg=0;
  int j;
  while(1){
    //printf("开始阻塞\n");
    j=semop(semid, op, 1);
    sleep(1);
    printf("解除阻塞！\n");
  }
  
  //删除
  return 0;
}
