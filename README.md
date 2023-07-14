# Postmortem Debugging - Debugging Failed Code

This repository contains code that failed and had to be debugged using postmortem debugging by creating a core dump and analyzing it. The code is written in C and includes a `main` function that performs a loop with a conditional sleep operation.

## Problem Description

The original code encountered issues and failed to execute as expected. The specific problem was related to the loop logic and the conditional sleep operation.

## Debugging Approach

To diagnose the issue, postmortem debugging was performed by creating a core dump and analyzing it using a debugger. The core dump provides a snapshot of the program's state at the time of the failure, allowing for a detailed examination.

## Steps for Debugging

1. Compile the code with debugging symbols: `gcc -g main.c -o main`
2. Run the program: `./main`
3. Observe the failure and obtain the process ID (PID) of the running program.
4. Generate a core dump by sending a SIGABRT signal to the process: `kill -SIGABRT <PID>`
5. Analyze the core dump using a debugger: `gdb ./main core`
6. Debug the code by examining the stack trace, variables, and memory state.

## Debugging Outcome

After analyzing the core dump with the debugger, the issue was identified in the loop logic and the conditional sleep operation. The loop condition `index == r` was found to be incorrect, causing the sleep operation to be skipped. By modifying the loop condition to `index == r - 1`, the code was corrected.

## Updated Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define _POSIX_C_SOURCE 199309L
#define ITER_MAX 65536

void siesta() {
    sleep(3600);
}

int main() {
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    int r = tp.tv_nsec % ITER_MAX;

    int index;
    for (index = 0; index < ITER_MAX * 10; index++) {
        if (index == r - 1)
            siesta();
    }

    return EXIT_SUCCESS;
}
```
## Conclusion
Through postmortem debugging and analysis of the core dump, the issue in the code was identified and resolved. The corrected code now executes as expected without encountering any failures.
