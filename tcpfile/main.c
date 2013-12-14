#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
int main(){
  int sfd, cfd, ffd;
  int r;
  int len;
  char buf[128];
  char filename[100];
  struct sockaddr_in dr;
   
  sfd=socket(AF_INET, SOCK_STREAM, 0);
  if(sfd==-1){
    printf("socket error %m\n");
    exit(-1);
  }
  printf("建立socket服务器成功!\n");
  
  dr.sin_family=AF_INET;
  dr.sin_port=htons(9988);
  dr.sin_addr.s_addr=inet_addr("192.168.1.159");
  r=bind(sfd, (struct sockaddr*)&dr, sizeof(dr));
  if(r==-1){
    printf("bind error: %m\n");
    close(sfd);
    exit(-1);
  }
  printf("绑定地址成功!\n");
  //3.监听  
  r=listen(sfd, 10);
  if(r==-1){
    printf("listen error: %m\n");
    close(sfd);
    exit(-1);
  }
  printf("listen successfully~\n");
  //接收连接
  cfd=accept(sfd, 0, 0);
  if(cfd==-1){
    printf("accept error:%m\n");
    close(sfd);
    exit(-1);
  }
  printf("Accept successfully~\n");

  //接收文件
  r=recv(cfd, &len ,sizeof(len), MSG_WAITALL);  
  printf("len:%d\n", len);
  r=recv(cfd, filename, len , MSG_WAITALL);
  filename[len]=0;
  printf("文件名：%s\n", filename);
  
  //创建文件
  ffd=open(filename, O_RDWR|O_CREAT, 0666);
  
  ////异常处理
  //循环接收文件数据
  while(1){
    r=recv(cfd, &len, sizeof(len), MSG_WAITALL);
    if(len==0){
      break;
    }
    r=recv(cfd, buf, len, MSG_WAITALL);
    
    write(ffd, buf, len);    

  }
  close(ffd);
  close(cfd);
  close(sfd);
  printf("文件接收完毕");



 













  return 0;
}

