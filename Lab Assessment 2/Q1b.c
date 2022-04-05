//FIFO - write 

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
   
#define BUFFER_SIZE 100

int main() 
{ 
    int fd; 
    char buff[BUFFER_SIZE] = "";

    FILE* ptr;
    ptr = fopen("input.txt", "r");
 
    if (NULL == ptr) 
    {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    int i=0;

    do 
    {
        char ch = fgetc(ptr);
        buff[i] = ch;
        i++;
    } while (ch != EOF);
 
    // Closing the file
    fclose(ptr);

    // FIFO file path 
    char myfifo[BUFFER_SIZE] = "/tmp/myfifo"; 

    // Creating a named file(FIFO) 
    mkfifo(myfifo, 0666); 
                              
    fd = open(myfifo, O_WRONLY); 
                                    
    // Write the input to FIFO and close it 
    write(fd, buff, strlen(buff)+1); 
    close(fd); 

    sleep(100);
    return 0; 
} 