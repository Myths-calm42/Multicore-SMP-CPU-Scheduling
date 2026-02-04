#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "process.h"

std::vector<Process> ReadFromUser();
std::vector<Process> ReadFromFile(const std::string& filename);
void PrintAverages(const std::vector<Process>& processes);

#endif
