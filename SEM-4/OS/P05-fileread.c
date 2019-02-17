#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

void main()
{
    int fd, sz;
    char *c = (char *) calloc(100, sizeof(char));

    fd = open("P05-create.txt", O_RDONLY);
    printf("fd = %d\n", fd);

    if (fd == -1)
    {
        // print which type of error have in a code
        printf("Error Number %d\n", errno);
        printf("cannot read the file");
    }
    else
    {
        sz = read(fd, c, 10);
        printf("called read(% d, c, 10). returned that %d bytes  were read.\n", fd, sz);
        c[sz] = &#39;\0&#39;;
        printf("Those bytes are as follows: % s\n", c);
    }
}