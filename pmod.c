#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main()
{
    nice(10);
    struct timespec t = {1, 837272638};
    nanosleep(&t, NULL);
    printf("Task has finished\n");
    return 0;
}