#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

void main()
{
    int fd;
    fd = creat("P05-create.txt", 0777);

    if (fd == -1)
        printf("error creating file fd = -1\n");
    else
        printf("created the file && fd: %d\n", fd);
}
