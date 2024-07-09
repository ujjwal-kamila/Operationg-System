#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
       #include <sys/types.h>
       #include <sys/stat.h>
//showing error in O_RDONLY and O_WRONLY
#include <fcntl.h>


int main() {
	if (mkfifo("myfifo", 0666) == -1 && errno != EEXIST) {
		perror("mkfifo");
		exit(1);
	}
	if (fork() == 0){
		close(STDOUT_FILENO);
		open("/tmp/myfifo", O_WRONLY);
		execlp("ls", "ls","-l", NULL);
	} else {
		close(STDIN_FILENO);
		open("/tmp/myfifo", O_RDONLY);
		execlp("wc", "wc", "-l", NULL);
	}
}
