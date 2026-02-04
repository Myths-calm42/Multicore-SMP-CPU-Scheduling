#ifndef CORE_H
#define CORE_H

#include <vector>

struct GanttEntry {
    int pid;
    int start;
    int end;
};

struct Core {
    int coreId = 0;
    int currentTime = 0;
    std::vector<GanttEntry> gantt;
};

#endif
