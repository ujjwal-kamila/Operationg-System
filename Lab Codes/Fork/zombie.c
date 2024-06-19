// Creating an zombie process using fork system call

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t t;
	t = fork();
	if (t == 0)
	{
		printf("child have id %d\n", getpid());
	}
	else
	{
		printf("Parent have id %d\n", getpid());
		sleep(1000);
	}
	return 0;
}
