#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int y=0;
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if(pid==0)
	{
		printf("Child - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
		printf("This is the child\n");
	}
	else
	{
		sleep(5);
		printf("This is parent terminating\n");
		printf("Parent - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
	}
	return 0;
}
