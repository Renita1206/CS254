#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    printf("\nThis is child. Process Id = %d\n", getpid());
    printf("Sum is %d\n",atoi(argv[0])+atoi(argv[1]));
    return 0;
}