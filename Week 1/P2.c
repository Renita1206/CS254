#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int i = 0;
	int y = 0;
	pid_t pid;
	pid = fork();
	if(pid>0) //Parent process
	{
		for(i=0;i<5;i++)
		{
			sleep(i);
			y=y-1;
		}
		printf("Parent - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
	}
	if(pid==0) //Child Process
	{
		for(i=0;i<5;i++)
		{
			sleep(i);
			y=y+1;
		}
		printf("Child - y: %d  pid: %d  ppid: %d\n", y, getpid(), getppid());
	}
	return 0;
}
