#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>  
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
int file;
char write_msg[BUFFER_SIZE] = "";
char read_msg[BUFFER_SIZE];
char myfile[BUFFER_SIZE] = "input.txt" ;
int fd[2];
pid_t pid;
/* create the pipe */
if (pipe(fd) == -1) {
fprintf(stderr,"Pipe failed");
return 1;
}
/* fork a child process */
pid = fork();
if (pid < 0) { /* error occurred */
fprintf(stderr, "Fork Failed");
return 1;
}
if (pid > 0) { /* parent process */
/* close the unused end of the pipe */
close(fd[READ_END]);

    file = open(myfile, O_RDONLY) ;
    read(file, write_msg, BUFFER_SIZE) ;
    close(file) ;
/* write to the pipe */
write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
/* close the write end of the pipe */
close(fd[WRITE_END]);
}
else { /* child process */
/* close the unused end of the pipe */
close(fd[WRITE_END]);
int lines, count, spaces, i;
lines = 0;
count = 0;
spaces = 0;
/* read from the pipe */
read(fd[READ_END], read_msg, BUFFER_SIZE);
printf("read :%s\n",read_msg);
i = 0;
while(read_msg[i] != '\0') {
if(read_msg[i] == ' ')
spaces++;
if(read_msg[i] == '\n')
lines++;
count++;
i++;
}
printf("Characters:%d\n Spaces: %d\n Lines:%d\n", count, spaces, lines);
/* close the write end of the pipe */
close(fd[READ_END]);
}
return 0;
}
