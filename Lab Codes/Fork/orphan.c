
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t t;
    t = fork();
    if (t == 0)
    {
        printf("Child having id %d\n", getpid());
        sleep(10);
        printf("I'm Living");
    }
    else
    {
        printf("Parent having id %d\n", getpid());
        exit(0);
    }
    return 0;
}