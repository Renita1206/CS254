#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

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
	for(int i = 0; i<5;i++)
	{
		if(pid1!=0)// Parent
		{
		    pid2 = fork();
		    if(pid2!=0)
		    	printf("%d) Parent: %d Child: %d\n",i, pid1, pid2);
		}
		if(pid2==0)
		{
			exit(0);
		}
	}
	return 0;
}