#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5555

int main(int argc,char *argv[]){
int sock=0;
struct sockaddr_in serv_addr;

if(argc!=2)
{
printf("\n Usage:%s <server IP address>\n",argv[0]);
return -1;
} 

if((sock = socket(AF_INET,SOCK_STREAM,0))<0){
printf("\nSOCKET CREATION ERROR\n");
return -1;
}

memset(&serv_addr,'0',sizeof(serv_addr));

serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(PORT);

if(inet_pton(AF_INET,argv[1], &serv_addr.sin_addr)<=0)
{
printf("\n Invalid address/Address not supported\n");
return -1;
}

if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
printf("\nConnection Failed\n");
return -1;
}

int readbytes =0,i;
char recvBuff[100];
char sendBuff[100];
for(;;){

i=0;
memset(sendBuff,'0',sizeof(sendBuff));
printf("ENTER THE STRING: ");
scanf("%s",sendBuff);

write(sock,sendBuff,sizeof(sendBuff));
memset(sendBuff,'0',sizeof(sendBuff));


readbytes=recv(sock,sendBuff,sizeof(sendBuff),0);
sendBuff[readbytes]=0;

printf("server:\n%s\n",sendBuff);
}

close (sock);
return 0;

}
