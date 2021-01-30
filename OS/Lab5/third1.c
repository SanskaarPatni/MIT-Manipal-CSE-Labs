#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdlib.h>
int main() 
{ 
    int fd; 
    char * myfifo = "/home/student/180905134/OS/Lab5/fifoSecond"; 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        fd = open(myfifo, O_WRONLY);
        if(fd!=-1) {
            fgets(arr2, 80, stdin); 
            write(fd, arr2, strlen(arr2)+1);
            arr2[0]='\0';
            close(fd);
        }  
        else{
            exit(EXIT_FAILURE);
        }
        fd = open(myfifo, O_RDONLY);
        if(fd!=-1) { 
            read(fd, arr1, sizeof(arr1)); 
            printf("User2: %s\n", arr1); 
            arr1[0]='\0';
            close(fd); 
        }
        else{
            exit(EXIT_FAILURE);
        }
    } 
    return 0; 
} 