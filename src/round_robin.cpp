#include <iostream>
#include <queue>
#include <algorithm>
#include "scheduler.h"
#include "core.h"

void MulticoreRoundRobin(std::vector<Process>& processes, int cores, int quantum) {
    std::queue<size_t> q;
    std::vector<int> remaining(processes.size());
    std::vector<Core> cpu(cores);

    for (size_t i = 0; i < processes.size(); i++) {
        remaining[i] = processes[i].burstTime;
        q.push(i);
    }

    int time = 0, core = 0;
    std::cout << "\n--- Round Robin Scheduling ---\n";

    while (!q.empty()) {
        size_t i = q.front(); q.pop();

        int exec = std::min(quantum, remaining[i]);
        int start = time;
        int end = time + exec;

        cpu[core].gantt.push_back({processes[i].pid, start, end});
        remaining[i] -= exec;
        time = end;

        if (remaining[i] > 0)
            q.push(i);
        else {
            processes[i].turnaroundTime = time - processes[i].arrivalTime;
            processes[i].waitingTime =
                processes[i].turnaroundTime - processes[i].burstTime;
        }

        core = (core + 1) % cores;
    }
}
