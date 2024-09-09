//Create a child process using fork 

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main (){
    pid_t q;
    printf("Before fork");
    q = fork();
    if(q<0){
        printf("Error");
    }

    //child process
    else if(q==0){
        printf("Child having pid %d\n",getpid());
        printf("My Parent's pid is %d\n",getppid());
    }
    
    //parent process
    else{
        printf("Parent having pid %d\n",getpid());
        printf("My child's pid %d\n",q);
    }

    printf("Common\n");
}


/*
// Create a sequence of p-->p1-->p2 parent child using fork
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t p;

    printf("before fork\n");

    // Create the first fork
    p = fork();

    if (p == 0) {
        // This block is executed by the first child
        pid_t q;

        printf("Inside first fork\n");

        // Create the second fork
        q = fork();

        if (q == 0) {
            // This block is executed by the second child
            printf("I am 2nd child having id %d\n", getpid());
            printf("My parent id is %d\n", getppid());
        }
        
        // This is executed by the first child and the second child
        printf("I am child having id %d\n", getpid());
        printf("My parent id is %d\n", getppid());
    } 
    
    else {
        // This block is executed by the parent of the first fork
        printf("My child id is %d\n", p);
        printf("I am parent having id %d\n", getpid());
    }

    printf("common\n");

    return 0;
}
*/