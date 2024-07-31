
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;

void handler(int n) {
	if (count < 10) {
		count++;
		printf("The count is :  %d\n",count);

	}
	else {
		printf("Ending...\n");
		exit(0);
	}


}
int main() {

	struct sigaction sa;
	sa.sa_handler = handler;

	if (sigaction(SIGALRM, &sa, NULL) == -1 ){
		perror("Sigaction");
		return 1;
	}


	while(1)
	{
		printf("Running ......%d\n",getpid());
		sleep(1);
		alarm(1);
	}


	return 0;

}
