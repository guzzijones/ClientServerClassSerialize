#include "protoExec.h"

protoExec::protoExec(const int & sock,std::string total_message,const std::string & remainder ):iprotoAbstract(
sock){
   _cmd=remainder;


}
void protoExec::sendBack(){


}
void protoExec::Do(){
 pid_t my_pid, parent_pid, child_pid;
   int status;

/* get and print my pid and my parent's pid. */

   my_pid = getpid();    parent_pid = getppid();
   printf("\n Parent: my pid is %d\n\n", my_pid);
   printf("Parent: my parent's pid is %d\n\n", parent_pid);

/* print error message if fork() fails */
   if((child_pid = fork()) < 0 )
   {
      perror("fork failure");
      throw std::runtime_error("fork failure"); 
   }

/* fork() == 0 for child process */

   if(child_pid == 0)
   {  printf("\nChild: I am a new-born process!\n\n");
      my_pid = getpid();    parent_pid = getppid();
      printf("Child: my pid is: %d\n\n", my_pid);
      printf("Child: my parent's pid is: %d\n\n", parent_pid);
      printf("Child: I will sleep 3 seconds and then execute - date - command \n\n");

      sleep(3); 
      printf("Child: Now, I woke up and am executing date command \n\n");
      execl("/bin/date", "date", 0, 0);
      perror("execl() failure!\n\n");
      //excel always returns -1 so it is not to be tested.
      //excel only returns if there was an error
      printf("This print is after execl() and should not have been executed if execl were successful! \n\n");
      exit(1); 
      throw std::runtime_error("Exec failure"); 
   }
/*
 * parent process
 */
   else
   {
      printf("\nParent: I created a child process.\n\n");
      printf("Parent: my child's pid is: %d\n\n", child_pid);
      system("ps -acefl | grep ercal");  printf("\n \n");
      wait(&status); /* can use wait(NULL) since exit status
                        from child is not used. */
      printf("\n Parent: my child is dead. I am going to leave.\n \n ");
   }
}
