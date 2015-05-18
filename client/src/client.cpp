extern "C"{
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
}
#include <string>
#include <iostream>
#include "protocolBaseServer.h"
#include "todoFactory.h"
BOOST_SERIALIZATION_ASSUME_ABSTRACT(atodo)
BOOST_CLASS_EXPORT(todoExec)


#include <memory>

int main(void)
{
   int sockfd = 0,n = 0;
   struct sockaddr_in serv_addr;

                                                          // data 
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }
 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(3000);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
   
    //0x01  is and execute object
   char mtype=0x01;
   std::string dataToSend = "ls -al /home/ajonen";

   auto tmpTodoFactory=todoFactory::create(); //create factory
   auto anExecTodo=tmpTodoFactory->createExec(dataToSend); //create ExecTodo from factory
   std::string toSend= tmpTodoFactory->save(anExecTodo);
   protocolBaseServer pclient(sockfd);
   pclient.DoWrite(toSend);

   //read the object sent back
   std::string received;
   pclient.DoRead();

   auto execReturned = tmpTodoFactory->load(pclient.getTotalMessage());
   execReturned->Do();

    
   //archive
   
  return 0;
}
