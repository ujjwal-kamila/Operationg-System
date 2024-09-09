//wait for process to change state

// take fork example


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>

int main (){
    pid_t q,w;
    int w1, wstatus;
    printf("Before fork\n");
    q = fork();
    if(q<0){
        printf("Error");
    }

    //child process
    else if(q==0){  //child
        printf("Child having pid %d\n",getpid());
        printf("My Parent's pid is %d\n",getppid());
    }
    
    else { //parent
        // w=wait(NULL);
        w1 = wait(&wstatus);
        printf("Status is : %d\n",WIFEXITED(wstatus));
        printf("Status is : %d\n",w1);
        printf("Parent having pid %d\n",getpid());
        printf("My child's pid %d\n",q);
    }

    printf("Common\n");
}