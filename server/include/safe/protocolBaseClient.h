#include "protoField.h"
#include <stdexcept>
//#include "protoService.h"
class protocolBaseClient{
private:
   protoField<int32_t> _totalMessage;
   protoField<int> _todo;
protected:

public:
   protocolBaseClient(){}; 
   protocolBaseClient(protoField<int> todo,protoField<int32_t> Message);
   //creates socket and sets two fields to be send
   bool DoRead();
   //uses protoService::DoWrite to send both field
   bool DoWrite(); 
   //uses protoService::DoRead to read 
};
