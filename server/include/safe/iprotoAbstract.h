#ifndef IPROTOABSTRACT_H
#define IPROTOABSTRACT_H

#include "protocolBaseServer.h"
class iprotoAbstract:public protoBaseServer{
private:


protected:


public:
   iprotoAbstract():protoBaseServer(){};
   virtual void Do();
   virtual void SendBack();
};

#endif

