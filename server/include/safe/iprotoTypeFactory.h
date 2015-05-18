#ifndef IPROTOTYPEFACTORY_H
#define IPROTOTYPEFACTORY_H
#include "iprotoAbstract.h"
#include <memory>
class iprotoTypeFactory:public protocolBaseServer{

   public:
   virtual std::unique_ptr<iprotoAbstract> createProtoType();
   virtual std::unique_ptr<iprotoAbstract> createProtoType(const std::string & name);
};

#endif
