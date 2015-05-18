#ifndef ATODO_H
#define ATODO_H

#include "protocolBaseServer.h"
#include <string>
#include <bitset>
#include <boost/serialization/string.hpp>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

//abstract class
class aTodo{
private:

   friend class boost::serialization::access;

protected:
   const char _initType;

public:
   aTodo():_initType(0x00){};

   aTodo(const char type):_initType(type){};

std::string  oarchive(){
   std::ostringstream archive_stream;
   {
   boost::archive::text_oarchive archive(archive_stream);
   archive << *this;
   }
   archive_stream.flush();
   std::string outbound_data=archive_stream.str();
   
   std::string  foutbound_data;
   foutbound_data=_initType;
   foutbound_data+=outbound_data;
   std::cout << "length: " << foutbound_data.length() << std::endl;
   return foutbound_data;
}

void SendBack(protocolBaseServer & in){
   std::string foutbound_data;
   foutbound_data=oarchive();
  in.DoWrite(foutbound_data);
}
   virtual void Do()=0;
   virtual ~aTodo(){};

   template<class Archive>
   void serialize(Archive & ar, unsigned int version){
      ar & _initType;
   };
   char getInitType(){return _initType;};
};

#endif
