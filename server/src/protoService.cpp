#ifndef PROTOSERVICE_CPP
#define PROTOSERVICE_CPP

#include "protoService.h"

template <typename T>
void protoService<T>::DoWrite(const int & sock,void * data,T size){
  T bytesWrite=0;
  std::cout << "Size to write: " << size << std::endl;
  while(bytesWrite!=size){
      T WriteThisTime;
      do{
      WriteThisTime=send(sock,data+bytesWrite,size-bytesWrite,0); // send the message length
      }while((WriteThisTime == -1) && (errno == EINTR));
      if(WriteThisTime<0){
      std::cout << "Write failure" << std::endl;
         throw std::runtime_error("DoWrite Error");
 
      }
      bytesWrite+=WriteThisTime;
   }  
}
template <typename T>
void protoService<T>::DoRead(const int & sock,void * data,T size){
  T bytesRead=0;
  while(bytesRead!=size){
      T readThisTime;
      do{
      readThisTime=recv(sock,data+bytesRead,size-bytesRead,0); // Receive the message length
      }while((readThisTime == -1) && (errno == EINTR));
      if(readThisTime<0){
         std::cout << "read failure" << std::endl;
         throw std::runtime_error("DoRead Error");
      }
      bytesRead+=readThisTime;
   }  
}

#endif

