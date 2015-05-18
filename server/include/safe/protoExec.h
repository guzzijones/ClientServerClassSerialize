#ifndef PROTOLIST_H
#define PROTOLIST_H
#include <string>
#include "iprotoAbstract.h"
#include <stdexcept>
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
}
//concrete derived class defined by the client
class protoExec:public iprotoAbstract{
private:
   int _sock;
   int _lengthOfCmd;
   std::string _cmd;
   std::string _resultStdOut;
   std::string _resultStdErr;

protected:

public:
protoExec(const int & sock,std::string total_message,const std::string & remainder );
  void Do();
   void sendBack();
};

#endif
