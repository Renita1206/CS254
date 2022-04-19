#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

long int findSize(char file_name[])
{
// opening the file in read mode
FILE* fp = fopen(file_name, "r");

// checking if the file exist or not
if (fp == NULL) {
printf("File Not Found!\n");
return -1;
}

fseek(fp, 0L, SEEK_END);

// calculating the size of the file
long int res = ftell(fp);

// closing the file
fclose(fp);

return res;
}

// Driver code
int main()
{

    struct dirent *de;  // Pointer for directory entry
    int size;
    printf("Enter file size in KB: ");
    scanf("%d", &size);
    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");
 
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }
 
   
    while ((de = readdir(dr)) != NULL) {
            //printf("Name: %s Size: %d\n", de->d_name, de->d_reclen);
    long int res = findSize(de->d_name);
    if(res > size*1000)
    printf("File name: %s\tSize :%ld bytes \n",de->d_name, res);  
    }
 
    closedir(dr);    
    return 0;
}
