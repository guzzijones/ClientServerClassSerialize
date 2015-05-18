#ifndef ATODO_H
#define ATODO_H
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/unique_ptr.hpp>

#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>

class aTodo{
  public: 
   static const unsigned _Type=0x00;
   virtual ~aTodo(){};
   virtual void Do()=0;
   virtual unsigned getInitType(){return _Type;};

   private:
   friend class boost::serialization::access;
   template  <class Ar> void serialize(Ar &, unsigned){};
};
#endif
