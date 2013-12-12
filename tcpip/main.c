#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

  int fd;//socket描述符
  struct sockaddr_in ad;//本机ip地址
  char buf[100];//接受数据缓冲
  struct sockaddr_in ad_snd;//发送者ip地址
  socklen_t len;//发送者ip的长度
  int r;

  fd=socket(AF_INET, SOCK_DGRAM, 17);
  if(fd==-1){
    printf("socket : %m\n");
    exit(-1);
  }
  printf("建立socket成功!\n");

  ad.sin_family=AF_INET;
  ad.sin_port=htons(11111);
  inet_aton("192.168.1.159",&ad.sin_addr);
  r=bind(fd, (struct sockaddr*)&ad, sizeof(ad));
  if(r==-1){
    printf("bind err:%m\n");
    exit(-1);
  }
  printf("绑定ip成功!\n");

  while(1){
    len=sizeof(ad_snd);
    r=recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr*)&ad_snd, &len);  
    if(r>0){
     buf[r]=0;
     //printf("发送者IP%s\n", buf);
     //printf("发送者IP%d\n", ad_snd.sin_addr);
     printf("发送者IP:%s,port:%hu, 数据：%s\n", inet_ntoa(ad_snd.sin_addr),ntohs(ad_snd.sin_port) , buf);
     sendto(fd, "古怪哟~", strlen("古怪哟~"), 0, (struct sockaddr*)&ad_snd, sizeof(ad_snd));
    }
    if(r==0){
      printf("发送方关闭连接\n");
      break;
    }
    if(r==-1){
      printf("网络故障!\n");
      break;
    }
  }
  close(fd);
  return 0;
}
