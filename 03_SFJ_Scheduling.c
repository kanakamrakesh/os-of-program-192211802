#include <stdio.h>

int main()
{
    int bt[10], wt[10], tat[10], p[10];
    int i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter Number of Process : ");
    scanf("%d", &n);

    printf("\nEnter Burst Time : \n");
    for (i = 0; i < n; i++)
    {
        printf("p[%d] :", i + 1);
        scanf("%d", &bt[i]);
    }

    // sorting burst time
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    // calculating waiting time and it's average
    wt[0] = 0;
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    printf("\nBurst Time\tWating Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\n%d\t\t%d\t\t%d", bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\n\nAverage Turnaround Time=%f\n", avg_tat);
}
