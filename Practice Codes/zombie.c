// Creating a zombie process 
/*
A zombie process is a process that has completed execution but still has an entry in the process table.
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main (){
    pid_t q;
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
        sleep(5);
        printf("Parent having pid %d\n",getpid());
        printf("My child's pid %d\n",q);
    }

}

