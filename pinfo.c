/*

finfo.c
A program designed to print the process components to the user
Carl Show
November 3rd, 2025

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>


int main(int argc, char* argv[])
{
    int willCont = 0; // Did we get the process
    pid_t pid;
    if(argc > 1)
    {
        if(getpgid(strtoul(argv[1], NULL, 10)) > -1)
        {
            pid = strtoul(argv[1], NULL, 10);
            willCont = 1;
        }
        else
            printf("Target PID does not exist\n");
    }
    else
    {
        printf("No target specified, defaulting to this process...\n");
        pid = getpid();
        willCont = 1;
    }
    if(willCont == 1)
    {
        printf("Priority: %i\n", 20 + getpriority(0, pid));
        char tempSched[50];
        switch(sched_getscheduler(pid))
        {
            case 0: 
                strcpy(tempSched, "Round-Robin standard");
            break;
            case 1: 
                strcpy(tempSched, "Batched");
            break;
            case 2: 
                strcpy(tempSched, "Idling");
            break;
            default: 
                strcpy(tempSched, "Unknown");
            break;
        }
        printf("Schedule: %s\n", tempSched);
    }
}