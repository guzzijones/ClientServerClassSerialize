#ifndef PROTOTYPEFACTORY_H
#define PROTOTYPEFACTORY_H
#include "iprotoTypeFactory.h"
#include "iprotoAbstract.h"
#include "protoExec.h"
#include "protocolBaseServer.h"
#include <memory>
//concrete factory
class protoTypeFactory:public iprotoTypeFactory{
   private:
   protoTypeFactory();
   //singleton implementation //copy and operator= are private;
   protoTypeFactory(const protoTypeFactory & in ) {};
   protoTypeFactory &operator=(const protoTypeFactory & in ){
   if (&in !=this)
    return *this;
   };

   protected:

   public:
   static std::unique_ptr<protoTypeFactory> Get();
   std::shared_ptr<iprotoAbstract> createProtoType(const protocolBaseServer & in);

};
#endif
