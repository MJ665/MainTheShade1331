#include <stdio.h>

int main() {
    int bt[20], wt[20], tat[20];
    int i, n;
    float wtavg, tatavg;

    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME");

    for (i = 0; i < n; i++) {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);

    printf("\nPress Enter to exit...");
    getchar(); // Wait for Enter key
    // Output:
    // Enter the number of processes -- 2
    // Enter Burst Time for Process 0 -- 2
    // Enter Burst Time for Process 1 -- 1
    //      PROCESS        BURST TIME       WAITING TIME    TURNAROUND TIME
    //      P0              2               0               2
    //      P1              1               2               3
    // Average Waiting Time -- 1.000000
    // Average Turnaround Time -- 2.500000
    // Press Enter to exit...
    return 0;
}