#include "ASocket.h"

BOOST_SERIALIZATION_ASSUME_ABSTRACT(atodo)
BOOST_CLASS_EXPORT(todoExec)

ASocket::ASocket(int inPort,int inMaxListenters){
  std::unique_ptr<todoFactory> tmpTodoFactory=todoFactory::create();
  _ATodoFactory=std::move(tmpTodoFactory);
 listenfd = socket(AF_INET,SOCK_STREAM,0);   
 maxListeners=inMaxListenters;
 port=inPort;
 if(listenfd < 0)
   throw std::runtime_error("SocketFailed to connect");
 //clear out serv_addr space
 serv_addr = new struct sockaddr_in;
 serv_addr->sin_family=AF_INET;
 serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
 serv_addr->sin_port=htons(port);
 
 std::cout << "next step is to bind" << std::endl;
 //serv_addr needs to be cast from sockaddr_in to sockaddr pointer
 bind(listenfd,(struct sockaddr*)(serv_addr),sizeof(*serv_addr));

}
void ASocket::listenSocket(){
   std::cout << "in listen socket" << std::endl;
//to debug comment out the while loop and the fork.
 if(listen(listenfd,maxListeners)==-1){
   throw std::runtime_error("failed to listen");
 }
 std::cout << "listenting on " << port << std::endl;
// printf("Listening on: %i", port );
//event loop 
// signal (SIGINT, handler);
signal(SIGCHLD,SIG_IGN);
 while(1){
   int newSockFd;
   newSockFd = accept(listenfd,(struct sockaddr*)NULL,NULL);
   if(newSockFd<0)
      std::cerr << "Error on Accept" << std::endl;
   int pid = fork();
   if(pid <0)
      std::cerr << "Error on Fork" << std::endl;
   if(pid ==0){//if pid = zero that means it is the child.
      close(listenfd);//close the parent file descriptor, we do not need it and then process will wait again.
      
      try{
         protocolBaseServer pBase(newSockFd);
         pBase.DoRead();
         std::string remainder=pBase.getTotalMessage();
         std::cout << "done reading" << std::endl; 
         std::unique_ptr<aTodo> DoThis;
         //instanciate an instance of aTodo to complete the action requested
         DoThis=_ATodoFactory->load(remainder);
         DoThis->Do();//do whatever
         std::string afterDone = _ATodoFactory->save(DoThis);
         pBase.DoWrite(afterDone);
      }catch(std::exception &e)
      {
         std::cout << "exception: " << e.what();
         exit(1);
      }
     
      exit(0);//exit child process
    }
    else
      close(newSockFd);//there was a problem

   }//end of while loop
   close(listenfd);
   //never happens;
}

ASocket::~ASocket(){
   delete serv_addr;

}

