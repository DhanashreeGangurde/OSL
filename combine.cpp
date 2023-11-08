#include <stdio.h>

struct Process {
    int id;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
};

void sjfPreemptive(struct Process pro[], int n);
void roundRobin(struct Process pro[], int n, int tq);

int main() {
    int n; // Number of pro
    int tq; // Time quantum for Round Robin
    printf("Enter the number of pro: ");
    scanf("%d", &n);

    printf("Enter time quantum for Round Robin: "); 
    scanf("%d", &tq);

    struct Process pro[n];
    for (int i = 0; i < n; i++) {
        pro[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &pro[i].at);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &pro[i].bt);
        pro[i].rt = pro[i].bt;
    }

    int choice;

    printf("Enter the scheduling algorithm:\n1. Shortest Job First (Preemptive)\n2. RoundRobin\n");
    scanf("%d", &choice);

    if (choice == 1) {
        sjfPreemptive(pro, n);
    } else if (choice == 2) {
        roundRobin(pro, n, tq);
    } else {
        printf("Invalnid choice. Please choose 1 or 2.\n");
    }
    

    return 0;
}

void sjfPreemptive(struct Process pro[], int n) 
{
    // Implement Shortest Job First (Preemptive) algorithm here

    int currentTime = 0;
    int completed = 0;

    while (completed < n)
    {
        int sjob = -1;
        int stime = 999999; // A large number as initial value

        for (int i = 0; i < n; i++) 
        {
            if (pro[i].at <= currentTime && pro[i].rt > 0) 
            {
                if (pro[i].rt < stime) 
                { 
                    sjob =i ;
                    stime = pro[i].rt;
                }
            }
        }

        if (sjob == -1) 
        {
            currentTime++;
        } 
        else 
        {
            pro[sjob].rt--;
            if (pro[sjob].rt == 0) 
            {
                completed++;
                int finishTime = currentTime + 1;
                pro[sjob].tat = finishTime - pro[sjob].at;
                pro[sjob].wt = pro[sjob].tat - pro[sjob].bt;
            }
            currentTime++;
        }      
    }

    // Calculate and display average waiting time and average turnaround time
    int totalwt = 0;
    int totaltat = 0;

    for (int i = 0; i < n; i++) {
        totalwt += pro[i].wt;
        totaltat += pro[i].tat;
    }

    double averagewt = (double)totalwt / n;
    double averagetat = (double)totaltat / n;

    printf("Average Waiting Time: %.2lf\n", averagewt);
    printf("Average Turnaround Time: %.2lf\n", averagetat);
}

void roundRobin(struct Process pro[], int n, int tq) {
    // Implement Round Robin algorithm here
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (pro[i].rt > 0 && pro[i].at <= currentTime) {
                if (pro[i].rt > tq) {
                    currentTime += tq;
                    pro[i].rt -= tq;
                } else {
                    currentTime += pro[i].rt;
                    pro[i].rt = 0;
                    completed++;
                    pro[i].tat = currentTime - pro[i].at;
                    pro[i].wt = pro[i].tat - pro[i].bt;
                }
            }
        }
    }

    // Calculate and display average waiting time and average turnaround time
    int totalwt = 0;
    int totaltat = 0;

    for (int i = 0; i < n; i++) {
        totalwt += pro[i].wt;
        totaltat += pro[i].tat;
    }

    double averagewt = (double)totalwt / n;
    double averagetat = (double)totaltat / n;

    printf("Average Waiting Time: %.2lf\n", averagewt);
    printf("Average Turnaround Time: %.2lf\n", averagetat);
}
sjf and rr