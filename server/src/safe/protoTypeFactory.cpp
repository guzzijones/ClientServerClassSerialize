#include "protoTypeFactory.h"
#include <bitset>

std::unique_ptr<protoTypeFactory> Get(){
   static std::unique_ptr<protoTypeFactory> instance;
   return std::move(instance);
}

std::shared_ptr<iprotoAbstract> createProtoType(const protocolBaseServer & in){
   const char type = in.getTotalMessage().at(0);   
   std::string remainder=in.getTotalMessage().substr(1);
   std::bitset<8> bType(type);
   if(bType==0x01 ){
//      std::shared_ptr<iprotoAbstract> tmp(new protoExec(in.getSock(),in.getTotalMessage(),remainder));
         iprotoAbstract * tmp=new protoExec(in.getSock(),in.getTotalMessage(),remainder);
      return std::move( tmp);
   }
   //if 02 protolist
/*   if(bType==0x02 ){
      std::shared_ptr<iprotoAbstract> tmp(new protoExec(in.getSock(),remainder));
      return std::move( tmp);
   }
*/
}


