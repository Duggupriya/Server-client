#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5555

void *printfunction(void *ptr);


int main(int argc,char *argv[]){
       
                int sd=0;
           
                int i,j;
                pid_t id;
                struct sockaddr_in serv,client;
                 
              

              sd = socket(AF_INET,SOCK_STREAM,0);
    
              memset(&serv,'0',sizeof(serv));
              
         

               serv.sin_family=AF_INET;
               serv.sin_addr.s_addr=htonl(INADDR_ANY);
               serv.sin_port=htons(PORT);

           bind(sd,(struct sockaddr*)&serv,sizeof(serv));

          listen(sd,5);
          printf("\nserver listening for connection\n");

while(1){

           
          
         pthread_t thread,thread1;
        pthread_create(&thread,NULL,printfunction,(void*)&sd);
        pthread_create(&thread1,NULL,printfunction,(void*)&sd);

pthread_join(thread,NULL);
pthread_join(thread1,NULL);
exit(0);
    
}
return 0;
}
void *printfunction(void *ptr){
int conn=*(int *)ptr;
int connfd=0,i,readbytes=0;
           connfd=accept(conn,(struct sockaddr*)NULL,NULL);
           printf("\nAccepted a connection\n");
char recvBuff[100],str[100];
for(;;){
i=0;
                          

memset(str,'0',sizeof(str));
                                     
readbytes=recv(connfd,str,sizeof(str),0);
str[readbytes]=0;
 printf("%s\n",str);


 memset(str,'0',sizeof(str));
 scanf("%s",str);


                               
write(connfd,str,sizeof(str));


                                     
                                   
                                    
}
pthread_exit(NULL);
}



