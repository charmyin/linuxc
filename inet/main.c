#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  in_addr_t nip=192<<24 | 168<<16 | 1<<8 | 159;
  printf("nip:%u\n", nip);
  char *ip="192.168.1.159";
  char cip[4]={192,168,1,159};
  
  //把整数转换为字符串ip---inet_ntoa
  struct in_addr sip={nip};
  int myip;
  //sip.s_addr=nip;  
  printf("%s\n", inet_ntoa(sip));
  
  myip=inet_addr(ip);
  printf("%u\n", myip);
  printf("%u.%u.%u.%u\n", myip>>24&255,myip>>16&255,myip>>8&255, myip>>0&255 );
  return 0;
}
