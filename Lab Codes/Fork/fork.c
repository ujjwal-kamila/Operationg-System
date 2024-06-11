#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (){
	int c;
	for(c = 0;c < 5; c++){
		pid_t p = fork();
		if(p == 0){
			printf("Child (pid = %u) \n", getpid());
		}
		else{
			printf("Parent(pid = %u) created Child (pid = %u) \n", getpid(),p);
		}
	}
	return 0;

}

// ./fork | grep -o "pid = [0-9]*" | uniq | wc -l