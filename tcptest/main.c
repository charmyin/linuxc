#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
int main(){
  int serverfd;
  int cfd;
  struct sockaddr_in sadr;
  struct sockaddr_in cadr;
  socklen_t len;
  int r;
  int portnum=18888;
  char buf[102];  
  //1.socket
  serverfd= socket(AF_INET, SOCK_STREAM, 0);
  if(serverfd==-1){
    printf("socket error: %m \n");
    exit(-1);
  }
  printf("建立成功\n");
  //2.bind
  sadr.sin_family=AF_INET;
  sadr.sin_port=htons(portnum);
  printf("Port Number: %d\n", portnum);
  inet_aton("192.168.1.159", &sadr.sin_addr);
  r=bind(serverfd, (struct sockaddr*)&sadr, sizeof(sadr));
  if(r==-1){
    printf("bind error: %m\n");
    exit(-1);
  }
  printf("服务器地址绑定成功!\n");
  //3.listen
  r=listen(serverfd, 10 ); 
  if(r==-1){
    printf("listen error: %m\n");
    exit(-1);
  }
  printf("指定监听服务器成功!\n");
  //4.accept
  //while(1){
    len=sizeof(cadr);
    cfd=accept(serverfd, (struct sockaddr*)&cadr, &len);
    printf("%d\n", len);
    printf("有人链接：%d, IP:%s:%u\n", cfd, inet_ntoa(cadr.sin_addr), ntohs(cadr.sin_port));
   //}
  //manage 
  while(1){
  r=recv(cfd, buf, 100, 0);
  if(r>0){
    buf[r]=0;
    printf("::%s\n", buf);
  }
  if(r==0){
    printf("链接断开!\n");
    break;
  }
  if(r==-1){
    printf("网络故障!\n");
    break;
  }
}
  close(cfd);
  close(serverfd);
  return 0;

}
