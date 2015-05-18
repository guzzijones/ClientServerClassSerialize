#ifndef PROTOEXEC_H
#define PROTOEXEC_H
#include "iprotoAbstract.h"
#include <string>
#include <memory>
class protoList:public iprotoAbstract{
private:
   int _sock;
   int _lengthOfCmd;
   std::string _dir;
   std::string _resultStdOut;
   std::string _resultStdErr;
   std::string _files;

protected:

public:
  virtual  void Do();
  virtual  void sendBack();
};

#endif
