#include <stdio.h>
#include <stdlib.h> 
#include <sys/signal.h> 
int pid;
void handler(int a){
    printf("pid:%d signal number is :%d\n",pid,a);
    sleep(3);
}

int main(){

    void (*h)(int);
    h=signal(SIGINT,handler);

    pid = fork();
    if(pid > 0){ 
        while(1){
        printf(" Parent Process\n");
        sleep(1);}
    }else{
        while(1){
        printf(" Child Process\n");
        sleep(1);}
    }
    return 0;
}
