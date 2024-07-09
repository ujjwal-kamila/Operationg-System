#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define FIFO_NAME "myfifo"

int main() {
    pid_t pid1, pid2, pid3;
    int fd;

    // Create the FIFO (named pipe)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // First child process
        fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dprintf(fd, "%d (parent %d). hello\n", getpid(), getppid());
        close(fd);
        exit(EXIT_SUCCESS);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Second child process
        fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dprintf(fd, "%d (parent %d). world\n", getpid(), getppid());
        close(fd);
        exit(EXIT_SUCCESS);
    }

    pid3 = fork();
    if (pid3 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid3 == 0) {
        // Third child process
        fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dprintf(fd, "%d (parent %d). of_linux\n", getpid(), getppid());
        close(fd);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Redirect stdin to the FIFO read end
    dup2(fd, STDIN_FILENO);
    close(fd);

    // Use cat to read from stdin (FIFO) and print to stdout
    execlp("cat", "cat", NULL);
    perror("execlp");
    exit(EXIT_FAILURE);

    return 0;
}

