#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process
{
    int id, at, bt, ct, tat, wt, pt;
    int completed; // To track completion
};

int findHighestPriority(struct Process p[], int n, int currentTime)
{
    int index = -1, highestPriority = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (p[i].at <= currentTime && !p[i].completed) // Process must have arrived and not be completed
        {
            if (p[i].pt < highestPriority || (p[i].pt == highestPriority && p[i].at < p[index].at))
            {
                highestPriority = p[i].pt;
                index = i;
            }
        }
    }
    return index;
}

void NonPreemptivePriority(struct Process p[], int n)
{
    int completedCount = 0, currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    while (completedCount < n)
    {
        int ind = findHighestPriority(p, n, currentTime);

        if (ind == -1) // If no process is available, move time forward
        {
            currentTime++;
        }
        else
        {
            // Process execution
            p[ind].completed = 1;
            completedCount++;
            currentTime += p[ind].bt;
            p[ind].ct = currentTime;
            p[ind].tat = p[ind].ct - p[ind].at;
            p[ind].wt = p[ind].tat - p[ind].bt;
            totalTAT += p[ind].tat;
            totalWT += p[ind].wt;
        }
    }

    printf("PID\tAT\tBT\tP\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average TAT = %.2f\n", totalTAT / n);
    printf("Average WT = %.2f\n", totalWT / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter Arrival Time (AT), Burst Time (BT), and Priority (P) for each process:\n");
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        p[i].completed = 0; // Initially, no process is completed
        printf("P%d (AT, BT, P): ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pt);
    }

    NonPreemptivePriority(p, n);
    return 0;
}
