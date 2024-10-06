#include <time.h>
#include <stdio.h>

#ifndef PROG_CLOCK
#define PROG_CLOCK

void progClock(int secs) {
    time_t prog_time = clock();
    while((float)prog_time / CLOCKS_PER_SEC <= secs) {
        prog_time = clock();
        // printf("%f\n", (float)prog_time / CLOCKS_PER_SEC);
    }
}

#endif