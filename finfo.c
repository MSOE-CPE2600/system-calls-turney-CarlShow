#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int willCont = 0;
    struct stat target;
    if(argc > 1)
    {
        int prod = stat(argv[1], &target);
        if(prod != -1)
        {
            willCont = 1;
        }
        else
        printf("Target file does not exist.\n");
    }
    else
    {
        printf("No file specified, Aborting...\n");
    }
    if(willCont == 1)
    {
        char generalBuffer[100];
        if(S_ISREG(target.st_mode))
        {
            sprintf(generalBuffer, "a regular file");
        }
        else if(S_ISDIR(target.st_mode))
        {
            sprintf(generalBuffer, "a directory");
        }
        else
        {
            sprintf(generalBuffer, "unknown");
        }
        printf("File is %s\n", generalBuffer);
        int runner = (target.st_mode >> 16)&15;
        if(runner == 7)
        {
            printf("User has full permissions over file\n");
        }
        else
        {
            printf("User may ");
            if(runner&&1)
                printf("excecute, ");
            if(runner&&2)
                printf("read, ");
            if(runner&&4)
                printf("write");
            printf("\n");
        }
        printf("User number %d is the owner of this file\n", target.st_uid);
        printf("File is %li bytes in size\n", target.st_size);
        strftime(generalBuffer, 100, "%D, %T", localtime(&target.st_mtim.tv_sec));
        printf("File was last edited %s\n", generalBuffer);
    }
}