#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "process.h"

void MulticoreFCFS(std::vector<Process>& processes, int cores);
void MulticoreSJF(std::vector<Process>& processes, int cores);
void MulticorePriority(std::vector<Process>& processes, int cores);
void MulticoreRoundRobin(std::vector<Process>& processes, int cores, int quantum);

#endif
