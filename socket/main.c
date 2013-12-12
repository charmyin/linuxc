#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/un.h>

int main(){
  int fd;
  //建立socket
  fd=socket(AF_UNIX,SOCK_DGRAM,0);
  if(fd==-1){
    printf("socket err:%m\n");
    exit(-1);
  }
  printf("%d:%d\n", getpid(), fd);
  //构造本地文件地址
  struct sockaddr_un addr={0};
  addr.sun_family=AF_UNIX;
  memcpy(addr.sun_path, "my.sock", strlen("my.sock"));
  //把socket绑定在地址之上
  int r;
  r=bind(fd, (struct sockaddr*)&addr, sizeof(addr));
  if(r==-1){
    printf("bind err:%m\n");
    exit(-1);
  }
  printf("地址绑定OK！\n");
  //4.接受数据
  char buf[200];
  bzero(buf,sizeof(buf));
  r=read(fd, buf, sizeof(buf));
  buf[r]=0;
  printf("%s\n", buf);
  //关闭
  close(fd);
  //删除sock文件
  while(1){
    
  }

  return 0;
}
