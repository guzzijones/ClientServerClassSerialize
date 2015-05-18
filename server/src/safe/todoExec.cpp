#include "todoExec.h"
const char todoExec::_TYPE=0x01;


todoExec::todoExec(std::string & command):_command(command),aTodo(_TYPE){
}
void todoExec::Do(){
//   std::cout << "Remainder: " << _initRemainder << std::endl;
   _execOutput="here is what happened;";
   _execError="no errors;";
}

