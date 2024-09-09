//C program that opens a file, duplicates the file descriptor using dup(), and prints both the original and the new file descriptors.

#include <unistd.h>   
#include <fcntl.h>     
#include <sys/types.h>  
#include <sys/stat.h>   
#include <stdio.h>

int main() {
    int fd1, fd2;
    // Open the file 'dup' in read-only mode
    fd1 = open("dup", O_RDONLY);
    
    // Print the old file descriptor
    printf("OLD file descriptor %d\n", fd1);
    // Duplicate the file descriptor
    fd2 = dup(fd1);
    // fd2 = dup2(fd1,7);   // replace value of new descr as 7 
    

    // Print the new file descriptor
    printf("NEW file descr. %d\n", fd2);

    return 0;
}
