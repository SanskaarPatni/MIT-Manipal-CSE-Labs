#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char arr[20][20];
    int i = 0;
    int count = 0;
    char temp[20];
    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }
    for (int i = 0; i < 20; i++)
    {
        arr[i][0] = '\0';
    }
    chdir(dir);
    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        // printf("%s\n", entry->d_name);
        if (S_ISDIR(statbuf.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
                continue;
            strcpy(arr[i++], entry->d_name);
            count++;
        }
    }
    for (i = 0; i < count; i++)
        for (int j = i + 1; j <= count; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", arr[i]);
    }
    chdir("..");
    closedir(dp);
}

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        char *dir = (char *)argv[1];
        printdir(dir, 0);
    }
    else
        printdir("/home", 0);
    exit(0);
}