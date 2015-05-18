#ifndef PROTOFIELD_H
#define PROTOFIELD_H
#include "protoService.h"
#include <string>
template <class T>
class protoField:protoService<T>{
private:
   T _length;
   std::string _value;
protected:

public:
   protoField(){};
   protoField(T length, std::string value);   
   protoField(const std::string & value);

   T getLength();
   std::string getValue();
   


};
#include "../src/protoField.cpp"
#endif
