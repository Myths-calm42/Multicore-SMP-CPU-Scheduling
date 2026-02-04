#include <iostream>
#include <fstream>
#include "utils.h"

std::vector<Process> ReadFromUser() {
    int n;
    std::cout << "Enter number of processes: ";
    std::cin >> n;

    std::vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        std::cout << "\nP" << p[i].pid << " Arrival: ";
        std::cin >> p[i].arrivalTime;
        std::cout << "Burst: ";
        std::cin >> p[i].burstTime;
        std::cout << "Priority: ";
        std::cin >> p[i].priority;
    }
    return p;
}

std::vector<Process> ReadFromFile(const std::string& file) {
    std::ifstream fin(file);
    std::vector<Process> p;

    Process temp;
    while (fin >> temp.pid >> temp.arrivalTime
               >> temp.burstTime >> temp.priority) {
        p.push_back(temp);
    }
    return p;
}

void PrintAverages(const std::vector<Process>& processes) {
    double wt = 0, tat = 0;

    for (const auto& p : processes) {
        wt += p.waitingTime;
        tat += p.turnaroundTime;
    }

    std::cout << "\nAverage Waiting Time: " << wt / processes.size();
    std::cout << "\nAverage Turnaround Time: " << tat / processes.size() << "\n";
}
