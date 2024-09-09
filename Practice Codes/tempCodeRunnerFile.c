//C program that opens a file, duplicates the file descriptor using dup(), and prints both the original and the new file descriptors.

// #include <unistd.h>   
// #include <fcntl.h>     
// #include <sys/types.h>  
// #include <sys/stat.h>   
// #include <stdio.h>

// int main() {
//     int fd1, fd2;
//     // Open the file 'dup' in read-only mode
//     fd1 = open("dup", O_RDONLY);
    
//     // Print the old file descriptor
//     printf("OLD file descriptor %d\n", fd1);
//     // Duplicate the file descriptor
//     // fd2 = dup(fd1);
//     fd2 = dup2(fd1,7);
    

//     // Print the new file descriptor
//     printf("NEW file descr. %d\n", fd2);

//     return 0;
// }



#include <unistd.h>   
#include <fcntl.h>     
#include <sys/types.h>  
#include <sys/stat.h>   
#include <stdio.h>

int main() {
    int fd1, fd2;
    // Open the file 'dup' in read-only mode
    fd1 = open("dup", O_RDONLY);
    
    // Check if open() failed
    if (fd1 == -1) {
        perror("Error opening file");
        return 1;
    }

    // Print the old file descriptor
    printf("OLD file descriptor %d\n", fd1);

    // Duplicate the file descriptor to 7
    fd2 = dup2(fd1, 7);

    // Check if dup2() failed
    if (fd2 == -1) {
        perror("Error duplicating file descriptor");
        close(fd1);  // Close the original file descriptor
        return 1;
    }

    // Print the new file descriptor
    printf("NEW file descriptor %d\n", fd2);

    // Close both file descriptors
    close(fd1);
    close(fd2);

    return 0;
}
