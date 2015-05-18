#include "aTodo.h"
#include <bitset>

aTodo::aTodo(const char type):_initType(type){

}
/*
//this method can be defined in the abstract class.  no need to repeat in derived clases
void aTodo::SendBack(protocolBaseServer & in){
   std::string foutbound_data;
   foutbound_data=oarchive();
  in.DoWrite(foutbound_data);
   //clean up new chars
}
*/

std::string  aTodo::oarchive(){
   std::ostringstream archive_stream;
   {
   boost::archive::text_oarchive archive(archive_stream);
   archive << *this;
   }
   archive_stream.flush();
   std::string outbound_data=archive_stream.str();
   
   std::string  foutbound_data;
   foutbound_data+=_initType;
   foutbound_data+=outbound_data;
   std::cout << "bit: " << std::bitset<8>(_initType) << std::endl;
   std::cout << "length: " << foutbound_data.length() << std::endl;
 
   return foutbound_data;


}
