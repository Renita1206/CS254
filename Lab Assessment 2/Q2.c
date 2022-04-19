#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 50
#define READ_END 0
#define WRITE_END 1

int main()
{	
	char write_msg1[BUFFER_SIZE] = "MESSAGE1";
	char write_msg2[BUFFER_SIZE] = "MESSAGE2";
	char write_msg3[BUFFER_SIZE] = "MESSAGE3";
	char read_msg[BUFFER_SIZE] = "";	
	int fd[2];
	int n;
	pid_t pid;
	
	// create pipe
	if(pipe(fd) == -1)
	{
		printf("Pipe failed\n");
		return 1;
	}
	
	pid = fork();
	
	if (pid>0)			
	{
		close(fd[READ_END]);
		write(fd[WRITE_END],write_msg3,BUFFER_SIZE);
		write(fd[WRITE_END],write_msg2,BUFFER_SIZE);
		write(fd[WRITE_END],write_msg1,BUFFER_SIZE);
		
		close(fd[WRITE_END]);
		wait(NULL);
	}
	else if (pid == 0)		
	{
		close(fd[WRITE_END]);
		while ((n = read(fd[READ_END],read_msg,BUFFER_SIZE)) > 0)
		{
			printf("Child process read: %s\n",read_msg);	
		}
		if (n != 0)
            		exit(2);
		close(fd[READ_END]);
	}
	else
	{
		printf("Fork failed\n");
		return 1;
	}
	return 0;
}


