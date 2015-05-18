#ifndef ATODOEXEC_H
#define ATODOEXEC_H
#include "aTodo.h"
#include <boost/serialization/base_object.hpp>
class todoExec : public aTodo{
   public:
   static const unsigned _TYPE= 0x01;
      todoExec(std::string const & command=""):_command(command){};
      virtual unsigned getInitType(){return  _TYPE;};
      virtual void Do(){std::cout << "foo:" << getCommand() << std::endl;};
      std::string getCommand() const {return _command;};
   protected:

   private: 
      friend class boost::serialization::access;
      template <class Archive> void serialize(Archive & ar, unsigned){
         boost::serialization::base_object<aTodo>(*this);
         ar& _command;
      }
   std::string _command;
};
#endif
