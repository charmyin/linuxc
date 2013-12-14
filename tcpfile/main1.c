#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main(){
  int sfd;
  int ffd;
  int r;
  int size;
  int len;
  char buf[128];
  struct sockaddr_in dr;
  char filename[]="test.c";
  //1.建立socket
  sfd=socket(AF_INET, SOCK_STREAM, 0);
  if(sfd==-1){
    printf("socket error: %m\n");
    exit(-1);
  }
  printf("socket successfully~\n");

  //2.链接到服务器
  dr.sin_family=AF_INET;
  dr.sin_port=htons(9988);
  inet_aton("192.168.1.159", &dr.sin_addr);
  r=connect(sfd, (struct sockaddr*)&dr, sizeof(dr));
  if(r==-1){
    printf("connect error: %m\n");
   close(sfd);
    exit(-1);
  }
  printf("Connect successfully!\n");
  //4.打开文件
  ffd=open(filename, O_RDONLY);
  if(ffd==-1){
    printf("open file %s error:%m\n", filename);
    close(sfd);
    exit(-1);
  }
  printf("Open file successfully!\n");
  //3.发送文件名
  len=strlen(filename);
  r=send(sfd,&len, sizeof(len), 0);  
  r=send(sfd,filename, len, 0);
  if(r==-1){
    printf("send error:%m\n");
    close(ffd);
    close(sfd);
    exit(-1);
  }
  printf("Send successfully~\n");
  
  //5.循环发送数据
  while(1){
    size=read(ffd, buf, 128);
    if(size==-1) {
      printf("read error:%m\n");
      break;
    }
    if(size==0) break;
    if(size>0){
      r=send(sfd, &size, sizeof(size), 0);//发送数据长度
      if(r==-1) break;
      r=send(sfd, buf, size, 0);//发送数据
      if(r==-1) break;
    }
    
  }
  //6.读取到文件尾，发送大小为0的数据包
  size=0;
  r=send(sfd, &size, sizeof(size), 0);
  close(ffd);
  close(sfd);
  printf("OK!\n");
}

