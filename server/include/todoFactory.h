#ifndef TODOFACTORY_H
#define TODOFACTORY_H

#include "todoExec.h"
#include <memory>


class todoFactory{

    todoFactory()=default;
   public:
      static std::unique_ptr<todoFactory> create(){return std::move(std::unique_ptr<todoFactory>(new todoFactory));};
      
      //save
      static std::string save(std::unique_ptr<aTodo> & todoIn){
         std::string out;
         {
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>>os(out);
            boost::archive::text_oarchive archive(os);

            archive << todoIn;
         }
         return out;

      }

      static std::unique_ptr<aTodo> load(std::string const &s ){
         std::unique_ptr<aTodo> p;
         {
            boost::iostreams::stream<boost::iostreams::array_source> is(boost::iostreams::array_source{s.data(),s.size()});
            boost::archive::text_iarchive archive(is);
            archive >> p;

         }
         return std::move(p);

       }

       std::unique_ptr<aTodo> createExec(std::string command) {return std::unique_ptr<aTodo>(new todoExec(command));};
   protected:

   private:



};
#endif
