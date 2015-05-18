#ifndef PROTOFIELD_CPP
#define PROTOFIELD_CPP 
#include "protoField.h"
template<typename T>
protoField<T>::protoField(T length, std::string value){   
  _length=length;
  _value=value;

}
template<typename T>
protoField<T>::protoField(const std::string  & value){   
  _value=value;
  _length=value.length();

}
template<typename T>
T protoField<T>::getLength(){
   return _length;

}
template<typename T>
std::string protoField<T>::getValue(){
   return _value;

}

#endif
