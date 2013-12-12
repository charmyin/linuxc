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
  //链接到指定地址
  struct sockaddr_un addr={0};
  addr.sun_family=AF_UNIX;
  memcpy(addr.sun_path, "my.sock", strlen("my.sock"));
  int r;
  r=connect(fd, (struct sockaddr*)&addr, sizeof(addr));
  //发送数据
  write(fd, "Hello maomaochong~",strlen("Hello maomaochong~"));
  //关闭
  close(fd);
  //删除sock文件

  return 0;
}
