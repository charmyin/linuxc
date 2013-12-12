#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct msgbuf{
  long type;
  char data[32];
};
main(){
  key_t key;
  int msgid;
  int i;
  //创建消息队列
  key=ftok(".", 200);
  if(key==-1){
    printf("ftok err:%m\n");
    exit(-1);
  }
  msgid=msgget(key, 0);
  if(msgid==-1){
    printf("get err:%m\n");
    exit(-1);
  }
  //构造消息
  struct msgbuf msg;

  //接受消息
  while(1){
    bzero(&msg, sizeof(msg));
    msg.type=2;
    msgrcv(msgid, &msg, sizeof(msg.data), 2, 0);
    printf("hello%s\n",msg.data ); 
  }
  //删除队列
  //msgctl(msgid, IPC_RMID, 0);

}
