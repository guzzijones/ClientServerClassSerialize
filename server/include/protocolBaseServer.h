#ifndef PROTOCOLBASESERVER_H
#define PROTOCOLBASESERVER_H
#include <stdexcept>
#include "protoService.h"
#include <bitset>
class protocolBaseServer{
private:
   std::string _totalMessage;
   int  _sock;
protected:

public:
   protocolBaseServer(){}; 
   protocolBaseServer(const int & sock);
   //creates socket and sets two fields to be send
   //uses protoService::DoWrite to send both field
   void DoRead();
   void DoWrite(const std::string & in); 
   //uses protoService::DoRead to read 
   std::string getTotalMessage()const{return _totalMessage;};
   int getSock()const{return _sock;};
   void setMessage(const std::string & in){_totalMessage=in;};
   
};
#endif
