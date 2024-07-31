#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int num) {
	printf("\nnah  don't tickle!!\n");
	exit(0);

}
int main() {

	struct sigaction sa;
	sa.sa_handler = handler;

	if (sigaction(SIGINT, &sa, NULL) == -1 ){
		perror("sigaction");
		return 1;
	}


	while(1)
	{
		printf("just running ........%d\n",getpid());
		sleep(1);
	}


	return 0;

}
