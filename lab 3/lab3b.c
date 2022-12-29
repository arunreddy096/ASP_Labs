#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
 
void main()
{
     int pid=fork();
    int s;  
    if(pid==0)
    {
    for(int i=0;i<30;i++){
    printf("process id of the child process is %d\n",getpid());
    printf("process id of the parent process is %d\n", getppid());
    sleep(1);
    }
    exit(EXIT_SUCCESS);
    }
    else if(pid<0)
    {
    printf("Error");
    }
    else
    {
    int k=wait(&s);     
    printf("\nThe pid of the parent process is %d\n",getpid());
    if (WIFEXITED(s))
            printf("Child process %d normally terminated with status: %d\n",pid, WEXITSTATUS(s));               
    if (WIFSIGNALED(s))
            printf("Child process %d terminated using kill with status: %d\n",pid, WTERMSIG(s));                
    }      
}
    
