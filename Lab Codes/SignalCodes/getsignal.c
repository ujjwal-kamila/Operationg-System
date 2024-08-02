#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int count = 0;

void signal_handler(int sig){
    printf("this is alarm no. %d\n", count);
    count++;

    if (count==6){
        printf("wake up stoopid!\n");
        signal(SIGALRM, SIG_DFL);
    }

    alarm(1);
}

int main(){
    signal(SIGALRM, signal_handler);

    alarm(1);
    while(1){
        pause();
    }
    return 0;
}