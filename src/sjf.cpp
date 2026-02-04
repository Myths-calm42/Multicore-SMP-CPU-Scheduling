#include <iostream>
#include <algorithm>
#include "scheduler.h"
#include "core.h"

void MulticoreSJF(std::vector<Process>& processes, int cores) {
    std::vector<Core> cpu(cores);

    std::sort(processes.begin(), processes.end(),
              [](const Process& a, const Process& b) {
                  return a.burstTime < b.burstTime;
              });

    std::cout << "\n--- SJF Scheduling ---\n";

    int idx = 0;
    for (auto& p : processes) {
        int c = idx % cores;

        if (cpu[c].currentTime < p.arrivalTime)
            cpu[c].currentTime = p.arrivalTime;

        int start = cpu[c].currentTime;
        int end = start + p.burstTime;

        p.waitingTime = start - p.arrivalTime;
        p.turnaroundTime = p.waitingTime + p.burstTime;

        cpu[c].currentTime = end;
        cpu[c].gantt.push_back({p.pid, start, end});

        std::cout << "P" << p.pid << " -> Core " << c << "\n";
        idx++;
    }
}
