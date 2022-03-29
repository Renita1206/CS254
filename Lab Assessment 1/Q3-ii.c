#include <stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

char *strdup (const char *s) {
    char *d = (char *)(malloc (strlen (s) + 1));
    if (d != NULL)
        strcpy (d,s);
    return d;
}

int main()
{
    printf("This is Parent. Process Id = %d\n", getpid());
    printf("Enter values a and b : ");
    int a,b;
    scanf("%d %d",&a,&b);
    char sprintf_buffer[20];
    char* argv[3];
    sprintf (sprintf_buffer, "%d",a);
    argv[1] = strdup (sprintf_buffer);
    sprintf (sprintf_buffer, "%d",b);
    argv[2] = strdup (sprintf_buffer);
    char* as;
    char* bs;
    if(fork()==0)
        execlp("./sum",argv[1],argv[2],(char *)0);
     sleep(5);
    // exit(0);
    return 0;
}


