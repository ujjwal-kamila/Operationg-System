// #include<stdio.h>
// #include<unistd.h>
// int main(){
// 	int n;
// 	n = write(1,"Hello",5);
// 	printf("\nvalue of n is %d\n",n);
// }



/*
Using user input
use read and write functions 
*/

# include<stdio.h>
# include<unistd.h>


int main() {
    char b[30];
	int m,n;
	printf("Enter 10 characters: ");
    // Read 10 characters from stdin (file descriptor 0)
    m=read(0, b, 10);
    // Write the same 10 characters to stdout (file descriptor 1)
	printf("\nThe input is: ");
    n=write(1, b, 10); 
	printf("\n Number of char enter is %d\n",n);
    return 0;
}
