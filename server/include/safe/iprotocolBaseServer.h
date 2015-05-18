#ifndef IPROTOCOLBASESERVER_H
#define IPROTOCOLBASESERVER_H
#include <stdexcept>
//#include "protoService.h"
class iprotocolBaseServer{
private:
   virtual void DoRead();
protected:

public:
   //creates socket and sets two fields to be send
   //uses protoService::DoWrite to send both field
   virtual void DoWrite(); 
   //uses protoService::DoRead to read 
   virtual std::string getTotalMessage()const;
};
#endif
