#ifndef SERVER_H
#define SERVER_H

//c
//:
#ifdef __cplusplus
extern "C"
{
#endif
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#ifdef __cplusplus
}
#endif

//c++
#include <iostream>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
#include <bitset>
#include "packUnPack.h"
#include <vector>
#include <string>
#include "protocolBaseServer.h"
#include "todoFactory.h"
#include <memory>
class ASocket{
private:
   std::unique_ptr<todoFactory> _ATodoFactory;
   int listenfd ,connf,maxListeners,port ;
   //define serv_addr as type sockaddr_in
   struct    sockaddr_in * serv_addr;
   int numrv;


protected:

public:
   
   ASocket(int port,int maxListeners);
   virtual ~ASocket();
   void listenSocket();
  // void DoStuff(int sock);
  // bool DoRead(const int & in,void * buff,uint32_t toRec);
  // bool DoWrite(const int & in,void * buff,uint32_t toRec);

};


#endif

