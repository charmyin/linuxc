#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int fd;
  //建立socket
  fd=socket(AF_INET,SOCK_DGRAM,0);
  if(fd==-1){
    printf("socket err:%m\n");
    exit(-1);
  }
  printf("%d:%d\n", getpid(), fd);
  //链接到指定地址
  struct sockaddr_in addr={0};
  addr.sin_family=AF_INET;
  int r;
  addr.sin_port=htons(9897);
  addr.sin_addr.s_addr=inet_addr("192.168.1.159");
  r=connect(fd, (struct sockaddr*)&addr, sizeof(addr));
  //发送数据
  write(fd, "Hello maomaochong~\nHello maomaochong~",strlen("Hello maomaochong~\nhello maomaochong~"));
  //关闭
  close(fd);
  //删除sock文件

  return 0;
}
