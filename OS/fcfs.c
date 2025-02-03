#include <stdio.h>
#include <string.h>

typedef struct process {
    int pid;
    char pname[10];
    int at, bt, ct, tt, wt;
} fcfs;

void getprocess(fcfs p[100], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter the %d process PID: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter the %d process name: ", i + 1);
        scanf("%s", p[i].pname); 
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
    }
}

void complete(fcfs p[100], int n) {
    int i;
    int t = 0; 
    for(i = 0; i < n; i++) {
        if(t < p[i].at) {
            t = p[i].at; 
        }
        t += p[i].bt; 
        p[i].ct = t; 
    }
}

void tt(fcfs p[100], int n) {
    int i;
    for(i = 0; i < n; i++) {
        p[i].tt = p[i].ct - p[i].at; 
    }
}

void wt(fcfs p[100], int n) {
    int i;
    for(i = 0; i < n; i++) {
        p[i].wt = p[i].tt - p[i].bt; 
    }
}

void print(fcfs p[100], int n) {
    printf("PID\tName\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    int i;
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                p[i].pid, p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    fcfs p[100]; 
    getprocess(p, n);
    complete(p, n);
    tt(p, n);
    wt(p, n);
    print(p, n); 
    return 0;
}
