#ifndef TODOEXEC_H
#define TODOEXEC_H

#include "aTodo.h"
#include <string>
#include <bitset>
#include <boost/serialization/string.hpp>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

// include headers that implement a archive in simple text format
class todoExec:public aTodo{
private:
  friend class boost::serialization::access;
   template<class Archive>
   void serialize(
            Archive& ar,
            unsigned int version
            )
    {
      std::cout << "serialize todoexec" << std::endl;
    //base
    boost::serialization::base_object<aTodo>(*this);
//derived
        ar & _command;
    }

  std::string _command;
protected:

public:
   static const char _TYPE=0x01;
   todoExec():aTodo(_TYPE){};
   todoExec(std::string command):aTodo(_TYPE){_command=command;};
   void Do(){std::cout << "foo" << std::endl;};
   virtual ~todoExec(){};

   std::string getCommand(){return _command;};
   

};

#endif
