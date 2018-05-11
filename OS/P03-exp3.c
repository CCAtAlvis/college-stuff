#include<stdio.h>
#include<unistd.h>

// create a child process in linux using fork() system call 
// from child process obtain the process id of both child and parent
// using getpid() and getppid() system call

void main()
{
	int pid;
	pid = fork();

	if (pid == 0)
	{
		printf("child process started, PID: %d \n", getpid());
	}
	else
	{
		printf("parent process id: %d \n", getppid());
	}
}
