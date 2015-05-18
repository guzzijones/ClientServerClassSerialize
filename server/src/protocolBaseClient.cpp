#include "protocolBase.h"

protocolBase::protocolBase(protoField<int> todo,protoField<int32_t> Message){
   
   int sockfd = 0,n = 0;
//   unsigned  char sendBuff[2];
   struct sockaddr_in serv_addr;
   int i = 200;
 //  packi16(sendBuff,i); 

                                                          // data 
  // strcat(total,(char*)sendBuffFloat);
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
//      printf("\n Error : Could not create socket \n");
      throw std::runtime_error("\n Error : Could not create socket \n");
    }
 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(3000);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      throw std::runtime_error("\nError : Connect Failed \n");
    //  printf("\n Error : Connect Failed \n");
//      return 1;
    }
}
bool protocolBase::DoRead(){

   
}
bool protocolBase::DoWrite(){ 

}

