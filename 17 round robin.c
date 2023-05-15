#include <stdio.h>

#define MAX_PROCESSES 10

struct process
{
    int id;
    int bt;
    int rt;
    int wt;
    int tat;
};

int main()
{
    struct process p[MAX_PROCESSES];
    int n, quantum, i, j, time = 0, total_wt = 0, total_tat = 0;

  
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    printf("Enter the CPU burst times for each process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
        p[i].rt = p[i].bt;
    }

  
    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                done = 0;

               
                if (p[i].rt == p[i].bt)
                {
                    p[i].wt = time;
                }

     
                if (p[i].rt <= quantum)
                {
                    time += p[i].rt;
                    p[i].rt = 0;
                }
                else
                {
                    time += quantum;
                    p[i].rt -= quantum;
                }

        
                p[i].tat = time - p[i].bt;

                total_wt += p[i].wt;
                total_tat += p[i].tat;
            }
        }

        if (done == 1)
        {
            break;
        }
    }


    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);

    return 0;
}
