/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: guille
 *
 * Created on March 21, 2022, 8:57 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define _POSIX_C_SOURCE 199309L
#define ITER_MAX 65536

void siesta() {
    sleep(3600);
}

/*
 * 
 */
int main() {
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    int r = tp.tv_nsec % ITER_MAX;

    int index;
    for (index = 0; index < ITER_MAX * 10; index++) {
        if (index == r)
            siesta();
    }

    return (EXIT_SUCCESS);
}

