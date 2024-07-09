#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main() {
	int pipefd[2];
	pipe(pipefd);
	if (fork() == 0) {
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		execlp("ls", "ls", NULL);
	} else {
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		execlp("wc", "wc", "-l", NULL);
	}
	return 0;

}
