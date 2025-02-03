#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;  

   
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    
    
    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);
    
    
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    
    
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

void sjfScheduling(int processes[], int n, int bt[]) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
               
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], bt[i] - 1, bt[i] * 2 - 1);
    }


    findAvgTime(processes, n, bt);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burst_time[n];
    
    printf("Enter the burst times for the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }
    
    sjfScheduling(processes, n, burst_time);
    
    return 0;
}

