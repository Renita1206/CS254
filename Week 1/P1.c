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
		y++;
		printf("Child - %d %d %d\n", y, getpid(), getppid());
	}
	else
	{
		y--;
		wait(NULL);
		printf("Parent - %d %d %d\n", y, getpid(), getppid());
	}
	return 0;
}
