#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int y = 0;
	pid_t pid1;
	pid_t pid2;
	pid1 = fork();
	if(pid1<0)
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if(pid1==0)
	{
		pid2 = fork();
		if(pid2>0)
		{
			y++;
			printf("Child 1 - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
		}
		if(pid2==0)
		{
			y=y+5;
			printf("Child 2 - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
		}
	}
	else
	{
		wait(NULL);
		y--;
		printf("Parent - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
	}
	return 0;
}
