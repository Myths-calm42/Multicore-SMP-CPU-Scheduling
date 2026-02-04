#include <iostream>
#include "scheduler.h"
#include "utils.h"

int main() {
    int choice, cores, quantum;

    std::cout << "1. Input from User\n2. Input from File\nChoice: ";
    std::cin >> choice;

    std::vector<Process> processes =
        (choice == 1) ? ReadFromUser() : ReadFromFile("input.txt");

    std::cout << "Enter number of cores: ";
    std::cin >> cores;

    std::cout << "Enter time quantum: ";
    std::cin >> quantum;

    MulticoreFCFS(processes, cores);
    PrintAverages(processes);

    MulticoreSJF(processes, cores);
    PrintAverages(processes);

    MulticorePriority(processes, cores);
    PrintAverages(processes);

    MulticoreRoundRobin(processes, cores, quantum);
    PrintAverages(processes);

    return 0;
}
