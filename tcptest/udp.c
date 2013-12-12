#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
int main(){
  int fd;
  struct sockaddr_in addr;
  int r;
  int portnum=18888;
  char buf[102];  
  //1.socket
  fd= socket(AF_INET, SOCK_STREAM, 0);
  if(fd==-1){
    printf("socket error: %m \n");
    exit(-1);
  }
  printf("建立成功\n");
  //2.connect
  addr.sin_family=AF_INET;
  addr.sin_port=htons(portnum);
  printf("Port Number: %d\n", portnum);
  inet_aton("192.168.1.159", &addr.sin_addr);
  r=bind(fd, (struct sockaddr*)&addr, sizeof(addr));
  if(r==-1){
    printf("bind error: %m\n");
    exit(-1);
  }
  printf("服务器地址绑定成功!\n");
  
  //4.accept
  int i;
  while(1){
     printf("send to server:%i\n",i);
     revc(fd, buf, 1024, 0);
     printf("::%s\n", buf);
  }
  
  return 0;

}
