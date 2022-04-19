#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
#define BUFFER_SIZE 100

int main() 
{ 
      int n=10;
   
     int arr[10];
     printf("Enter the contents of array\n");
     for(int i=0;i<n;i++)
     {
     scanf("%d",&arr[i]);
     }
    


     printf("Parent process reading the array\n");         
     for(int i=0;i<n/2;i++)
     {
         printf("%d",arr[i]);
     }
   
    
         
   
    int pid = fork();
    if(pid==0)
    {        
        printf("Child process reading the array");                  
        for(int i=n/2;i<n;i++)
        {
            printf("%d",arr[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        printf("SUm=%d",sum);
    
    }
                                             
    return 0; 
}
