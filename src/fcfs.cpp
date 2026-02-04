#include <iostream>
#include <algorithm>
#include "scheduler.h"
#include "core.h"

void MulticoreFCFS(std::vector<Process>& processes, int cores) {
    std::vector<Core> cpu(cores);
    for (int i = 0; i < cores; i++) cpu[i].coreId = i;

    std::sort(processes.begin(), processes.end(),
              [](const Process& a, const Process& b) {
                  return a.arrivalTime < b.arrivalTime;
              });

    std::cout << "\n--- FCFS Scheduling ---\n";

    for (auto& p : processes) {
        int best = 0;
        for (int i = 1; i < cores; i++)
            if (cpu[i].currentTime < cpu[best].currentTime)
                best = i;

        if (cpu[best].currentTime < p.arrivalTime)
            cpu[best].currentTime = p.arrivalTime;

        int start = cpu[best].currentTime;
        int end = start + p.burstTime;

        p.waitingTime = start - p.arrivalTime;
        p.turnaroundTime = p.waitingTime + p.burstTime;

        cpu[best].currentTime = end;
        cpu[best].gantt.push_back({p.pid, start, end});

        std::cout << "P" << p.pid << " -> Core " << best << "\n";
    }

    std::cout << "\nGantt Chart:\n";
    for (const auto& c : cpu) {
        std::cout << "Core " << c.coreId << ": ";
        for (const auto& g : c.gantt)
            std::cout << "| P" << g.pid << " (" << g.start << "-" << g.end << ") ";
        std::cout << "|\n";
    }
}
