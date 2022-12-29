#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
int pid;
long int p= getpid();
pid = fork();
pid = fork();
pid = fork();

if(pid == 0){
if(getppid() != p){
	char *programName = "ls";
	char *args[] = {programName, NULL};  
	int k=execvp(programName, args);
}
}
else{
printf("Error\n");
}

return 0;
}
