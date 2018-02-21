#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

void main()
{
    int fd;
    fd = open("P05-file.txt", O_RDONLY | O_CREAT);
    printf("fd = %d\n", fd);

    if (fd < 0)
    {
        perror("c1");
    }
    printf("opened the fd = % d\n", fd);
     
    // Using close system Call
    if (close(fd) < 0)
    {
        perror("c1");
    }

    printf("closed the fd.\n");
    if (fd == -1)
    {
        // print which type of error have in a code
        printf("Error Number %d\n", errno);

        // print program detail "Success or failure"
        perror("Program");                
    }
}
