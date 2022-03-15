#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
	char s[100], command[100] = "/bin/";
	printf("Enter command to be executed: ");
	scanf("%s",s);
	strcat(command, s);
	execlp(command, s, NULL);
	return 0;	
}