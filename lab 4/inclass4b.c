#include <stdio.h>
#include <stdlib.h> 
#include <sys/signal.h> 

void hand3(int a){}
void hand(int a);

void hand2(int a){
    printf("\nRecieved two CTR+C signals \n");
    void (*handler)(int);
    handler=signal(SIGINT,hand);

}

void hand(int a){
    printf("\nctrl + c is pressed waiting for 2nd one \n");

    void (*h1)(int);
    h1=signal(SIGINT,hand2);

    void (*h2)(int);
    h2=signal(SIGALRM,hand3);
    alarm(5);
    pause();
    
    
}

int main(){
    while(1){
    printf("\npause state\n");
    void (*h)(int);
    h=signal(SIGINT,hand);
    pause();
    }
    return 0;
}
