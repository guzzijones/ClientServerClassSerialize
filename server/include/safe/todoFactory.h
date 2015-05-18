#include "todoExec.h"
#include <string>
#include <bitset>
#include <boost/serialization/string.hpp>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

class todoFactory{
private:

protected:


public:
   std::unique_ptr<aTodo> retrieveAtodo(const std::string & total){
   std::cout << "here" << std::endl;
   char type=total.at(0);
   std::cout << "bitset: " << std::bitset<8>(type) << std::endl;
   std::string remainder=total.substr(1);
   if(type==0x01){
      std::cout << "remainder in retrieve: " << remainder << std::endl;
      std::unique_ptr<todoExec> tmp(new todoExec());
      std::stringstream archive_stream(remainder);
      std::cout << "stream remainder: " << archive_stream.str() << std::endl;
   {     
      boost::archive::text_iarchive archive(archive_stream);
      archive >> *tmp;
      }
      std::cout << "unserialized type: " << std::bitset<8>(tmp->getInitType()) << std::endl;
      return std::move(tmp);
   }
   };

   std::unique_ptr<aTodo> createAtodo(char type,std::string command){

      if(type==0x01){
         std::unique_ptr<todoExec> tmp(new todoExec(command));
         return std::move(tmp);
      }
   };


};

int main(){
    //0x01  is and execute object
   char mtype=0x01;
   std::string dataToSend = "ls -al /home/ajonen";

   std::unique_ptr<todoFactory> tmpTodoFactory; //create factory
   std::unique_ptr<aTodo> anExecTodo=tmpTodoFactory->createAtodo(mtype,dataToSend); //create ExecTodo from factory

   //archive
   std::string remainder = anExecTodo->oarchive();
   //now read in results that are sent back
   std::unique_ptr<aTodo> theResult;
   theResult=tmpTodoFactory->retrieveAtodo(remainder);
   std::cout << "resultant type: " << std::bitset<8>(theResult->getInitType()) <<std::endl;
   if(auto* d = dynamic_cast<todoExec*>(theResult.get()))
      std::cout << "resultant Command: " << d->getCommand() <<std::endl;
 

   return 0;
}

