/*

finfo.c
A program designed to do very little.
Carl Show
November 3rd, 2025

*/

#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main()
{
    nice(10); // Decrease the nicity
    struct timespec t = {1, 837272638};
    nanosleep(&t, NULL); // Snooze on it
    printf("Task has finished\n");
    return 0;
}