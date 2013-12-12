#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int fd;
  struct sockaddr_in ad;
  char buf[101];
  int r;
  
  fd=socket(AF_INET, SOCK_DGRAM, 17);
  if(fd==-1){
    printf("open socket error : %m \n");
    exit(-1);
  }
  
  ad.sin_family=AF_INET;
  ad.sin_port=htons(11111);
  ad.sin_addr.s_addr=inet_addr("192.168.1.159");
  connect(fd, (struct sockaddr*)&ad, sizeof(ad)); 
  while(1){
    r=read(0, buf, sizeof(buf)-1);
    if(r<=0){
      break;
    }
    buf[r]=0;
    r=send(fd, buf, r, 0);
   // r=sendto(fd, buf, r, 0, (struct sockaddr*)&ad, sizeof(ad));
    bzero(buf, sizeof(buf));
    r=recv(fd, buf, sizeof(buf), 0);
    buf[r]=0;
    printf("接收到数据：%s\n", buf);
    if(r==-1){
      break;
    }
  }
  close(fd);
  
  //删除
  return 0;
}
