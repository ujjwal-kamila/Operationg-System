//Create a orphan process using fork code

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
        sleep(5);
        printf("Child having pid %d\n",getpid());
        printf("My Parent's pid is %d\n",getppid());
    }
    
    //parent process
    else{
        printf("Parent having pid %d\n",getpid());
        printf("My child's pid %d\n",q);
    }

}

