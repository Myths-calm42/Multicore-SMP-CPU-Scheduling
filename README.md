# Multicore SMP CPU Scheduling Simulator

This project is a **C++ simulation of Multicore Symmetric
Multiprocessing (SMP) CPU Scheduling algorithms**.\
It demonstrates how an operating system schedules processes across
**multiple CPU cores** using different scheduling strategies and
evaluates their performance.

------------------------------------------------------------------------

##  Features

-   Multicore CPU scheduling simulation
-   Supported scheduling algorithms:
    -   First Come First Serve (FCFS)
    -   Shortest Job First (SJF)
    -   Priority Scheduling
    -   Round Robin
-   Gantt chart visualization with **start and end time**
-   Waiting time and turnaround time calculation
-   Flexible input support:
    -   User input (keyboard)
    -   File input (`input.txt`)
-   Modular and clean C++ project structure

------------------------------------------------------------------------

##  Project Directory Structure

    Multicore-SMP-CPU-Scheduling/
    │
    ├── include/
    │   ├── process.h
    │   ├── core.h
    │   ├── scheduler.h
    │   └── utils.h
    │
    ├── src/
    │   ├── main.cpp
    │   ├── fcfs.cpp
    │   ├── sjf.cpp
    │   ├── priority.cpp
    │   ├── round_robin.cpp
    │   └── utils.cpp
    │
    ├── input.txt
    ├── README.md
    ├── LICENSE
    └── .gitignore

------------------------------------------------------------------------

##  Input Format

Each line in `input.txt`:

    PID ArrivalTime BurstTime Priority

Example:

    1 0 5 2
    2 1 3 1
    3 2 8 3
    4 3 6 2

------------------------------------------------------------------------

##  Build and Run

``` bash
g++ src/*.cpp -Iinclude -std=c++17 -Wall -o scheduler
./scheduler
```

------------------------------------------------------------------------

##  License

MIT License
