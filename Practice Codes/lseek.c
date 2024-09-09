//Crate a file and read write specific char in that file 

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main (){
    int n ,f1,f2;
    char buff[50];
    f1 = open ("seek",O_RDWR);

    read(f1,buff,10);
    write(1,buff,10);

    lseek(f1,10,SEEK_CUR);  // skip 10 char 
    read(f1,buff,10);
    write(1,buff,10);


}