#include <stdio.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int completed;
} Process;

// Function to display final results
void displayResults(Process processes[], int n) {
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    printf("\n========================================\n");
    printf("           SCHEDULING RESULTS\n");
    printf("========================================\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].burstTime,
               processes[i].waitingTime,
               processes[i].turnaroundTime);

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f\n",
           totalWaitingTime / n);

    printf("Average Turnaround Time: %.2f\n",
           totalTurnaroundTime / n);
}

// FCFS Scheduling
void fcfs(Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = currentTime;
        currentTime += processes[i].burstTime;
        processes[i].turnaroundTime = currentTime;
    }

    printf("\nFCFS Scheduling Completed!\n");
    displayResults(processes, n);
}

// SJF Scheduling (Non-Preemptive)
void sjf(Process processes[], int n) {
    Process temp[MAX_PROCESSES];

    // Copy original processes
    for (int i = 0; i < n; i++) {
        temp[i] = processes[i];
    }

    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j].burstTime > temp[j + 1].burstTime) {
                Process swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        temp[i].waitingTime = currentTime;
        currentTime += temp[i].burstTime;
        temp[i].turnaroundTime = currentTime;
    }

    printf("\nSJF Scheduling Completed!\n");
    displayResults(temp, n);
}

// Round Robin Scheduling
void roundRobin(Process processes[], int n, int quantum) {
    Process temp[MAX_PROCESSES];

    // Copy processes and initialize remaining time
    for (int i = 0; i < n; i++) {
        temp[i] = processes[i];
        temp[i].remainingTime = temp[i].burstTime;
        temp[i].completed = 0;
    }

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {

        for (int i = 0; i < n; i++) {

            if (temp[i].remainingTime > 0) {

                if (temp[i].remainingTime > quantum) {
                    currentTime += quantum;
                    temp[i].remainingTime -= quantum;
                } else {
                    currentTime += temp[i].remainingTime;
                    temp[i].remainingTime = 0;
                    temp[i].turnaroundTime = currentTime;
                    temp[i].waitingTime =
                        temp[i].turnaroundTime - temp[i].burstTime;
                    completedProcesses++;
                }
            }
        }
    }

    printf("\nRound Robin Scheduling Completed!\n");
    printf("Time Quantum: %d\n", quantum);
    displayResults(temp, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("=====================================\n");
    printf("      CPU SCHEDULING SIMULATOR\n");
    printf("=====================================\n");

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    // Get burst times from user
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);

        if (processes[i].burstTime <= 0) {
            printf("Burst time must be greater than 0!\n");
            return 1;
        }

        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
        processes[i].completed = 0;
    }

    while (1) {
        printf("\n----------- MENU -----------\n");
        printf("1. First-Come, First-Served (FCFS)\n");
        printf("2. Shortest Job First (SJF)\n");
        printf("3. Round Robin (RR)\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fcfs(processes, n);
                break;

            case 2:
                sjf(processes, n);
                break;

            case 3:
                printf("Enter time quantum: ");
                scanf("%d", &quantum);

                if (quantum <= 0) {
                    printf("Time quantum must be greater than 0!\n");
                } else {
                    roundRobin(processes, n, quantum);
                }
                break;

            case 4:
                printf("\nExiting CPU Scheduling Simulator...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}