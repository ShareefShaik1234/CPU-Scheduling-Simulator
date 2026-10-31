# CPU Scheduling Simulator in C

## Overview

This project is a simple CPU Scheduling Simulator developed using C. It demonstrates how an operating system can select processes for CPU execution using different scheduling algorithms.

Users can enter the number of processes and their burst times, select a scheduling algorithm, and view the calculated performance results.

## Implemented Algorithms

The simulator includes the following algorithms:

- **First-Come, First-Served (FCFS)** – Executes processes in the order they are entered.
- **Shortest Job First (SJF)** – Executes the process with the shortest burst time first.
- **Round Robin (RR)** – Gives each process a fixed amount of CPU time in each cycle.

## Key Features

- Accepts multiple processes as input
- Supports three CPU scheduling algorithms
- Allows the user to specify the Round Robin time quantum
- Calculates individual waiting times
- Calculates individual turnaround times
- Displays average waiting and turnaround times
- Uses a simple menu-driven interface

## Concepts Used

- C Programming
- Structures
- Arrays
- Loops and Functions
- CPU Scheduling
- Operating System Fundamentals

## Project Files

```text
CPU-Scheduling-Simulator/
│
├── cpu_scheduler.c
└── README.md
```

## Compilation

Compile the program using GCC:

```bash
gcc cpu_scheduler.c -o cpu_scheduler
```

## Running the Program

For Windows PowerShell:

```powershell
.\cpu_scheduler
```

## Sample Input

```text
Enter number of processes: 4

Enter burst time for P1: 5
Enter burst time for P2: 3
Enter burst time for P3: 8
Enter burst time for P4: 2
```

After entering the process details, select an option from the menu to run FCFS, SJF, or Round Robin scheduling.

## Learning Outcomes

This project helped me understand how different CPU scheduling algorithms work and how their performance can be compared using waiting time and turnaround time. It also provided practical experience with C structures, arrays, functions, and basic operating system concepts.

## Author

**Shaik Baba Shareef**

GitHub: https://github.com/ShareefShaik1234
