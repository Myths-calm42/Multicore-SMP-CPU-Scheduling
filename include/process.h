#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;

    int waitingTime = 0;
    int turnaroundTime = 0;
};

#endif
