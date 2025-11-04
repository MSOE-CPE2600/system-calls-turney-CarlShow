/*

info.c
A program designed to print some basic hardware info to the user
Carl Show
November 3rd, 2025

*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

int main()
{
    char buffer[50]; 
    gethostname(buffer, 50); // Get our host name
    printf("HOST - You're hosting %s\n", buffer);
    struct timespec curTime; // Get the time since epoch
    clock_gettime(CLOCK_REALTIME, &curTime);
    struct tm time = *localtime(&curTime.tv_sec); // Convert that into a more local time
    printf("TIME - It has been %i:%li nanoseconds since this morning\n", (time.tm_sec + time.tm_min*60 + time.tm_hour*3600), curTime.tv_nsec);
    struct utsname os;
    uname(&os); // Get some primitive OS info
    printf("OS - You are running the %s operating system of version %s\n", os.sysname, os.release);
    long processors = sysconf(_SC_NPROCESSORS_ONLN); // Get some basic processor info
    if(processors > -1)
        printf("CPU - You have %li CPU processors\n", processors);
    else
        printf("CPU - Cannot get CPU information... Continuing\n");
    long blockNum = sysconf(_SC_PHYS_PAGES); // Get all necessary memory info
    long blockRem = sysconf(_SC_AVPHYS_PAGES);
    long blockSize = sysconf(_SC_PAGESIZE);
    if(blockNum > -1 && blockSize > -1)
        printf("MEM - You have a total of %li bytes of memory, with %li bytes remaining\n", blockNum*blockSize, blockRem*blockSize);
    else
        printf("MEM - Cannot get Memory information... Continuing\n");
}