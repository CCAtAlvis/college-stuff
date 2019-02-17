#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

void main()
{
    int fd;
    fd = open("P05-create.txt", O_RDONLY | O_CREAT);
    printf("fd = %d\n", fd);

    if (fd == -1)
    {
        // print which type of error have in a code
        printf("Error Number %d\n", errno);

        // print program detail "Success or failure"
        perror("Program");                
    }
}
