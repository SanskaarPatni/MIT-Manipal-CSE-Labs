#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include<stdlib.h>
int main() 
{ 
    int fd1;  
    char * myfifo = "/home/student/180905134/OS/Lab5/fifoSecond";
    mkfifo(myfifo, 0666);  
    char str1[80], str2[80]; 
    while (1) 
    { 
        fd1 = open(myfifo,O_RDONLY); 
        if(fd1!=-1) {
            read(fd1, str1, 80); 
            printf("User1: %s\n", str1); 
            str1[0]='\0';
            close(fd1); 
        } 
        else
        {
            exit(EXIT_FAILURE);
        }
        fd1 = open(myfifo,O_WRONLY);
        if(fd1!=-1) { 
            fgets(str2, 80, stdin); 
            write(fd1, str2, strlen(str2)+1);
            str2[0]='\0'; 
            close(fd1); 
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    } 
    return 0; 
} 