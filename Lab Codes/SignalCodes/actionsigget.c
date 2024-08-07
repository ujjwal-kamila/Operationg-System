#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct sigaction oldaction;
int count = 0;

void sig_handler(int sig){
    printf("this is alarm no. %d\n", count);
    count++;

    if (count == 6){
        printf("wake up ooga booga\n");
        sigaction(SIGALRM , &oldaction, NULL);
    }
    alarm(1);
}

int main(){
    struct sigaction sa;

    sa.sa_handler = &sig_handler;
    sigaction(SIGALRM , &sa, &oldaction);

    alarm(1);
    while(1){
        pause();
    }

    return 0;
}
