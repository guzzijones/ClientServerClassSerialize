#ifndef TODOFACTORY_CPP
#define TODOFACTORY_CPP

#ifndef TODOFACTORY_H
#include "todoFactory.h"
#endif

std::unique_ptr<aTodo> todoFactory::retrieveAtodo(char type,std::string remainder){
   if(type==0x01){

      std::unique_ptr<todoExec> tmp(new todoExec());
      std::istringstream archive_stream(remainder);
      boost::archive::text_iarchive archive(archive_stream);
      archive >> *tmp;
      return std::move(tmp);
   }
}

std::unique_ptr<aTodo> todoFactory::createAtodo(char type,std::string totalMsg){

   if(type==0x01){
      std::unique_ptr<todoExec> tmp(new todoExec(totalMsg));
      return std::move(tmp);
   }
}


#endif
