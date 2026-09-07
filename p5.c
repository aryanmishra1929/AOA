#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int deadline[20], profit[20];
    char job[20], tempJob;
    int slot[20] = {0};
    int maxProfit = 0, maxD = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        job[i] = 'A' + i;

        printf("\nEnter deadline and profit of Job %c: ", job[i]);
        scanf("%d %d", &deadline[i], &profit[i]);

        if(deadline[i] > maxD)
            maxD = deadline[i];
    }

    // Sort jobs by profit
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(profit[i] < profit[j])
            {
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;

                tempJob = job[i];
                job[i] = job[j];
                job[j] = tempJob;
            }
        }
    }

    // Schedule jobs
    for(i = 0; i < n; i++)
    {
        for(j = deadline[i]; j >= 1; j--)
        {
            if(slot[j] == 0)
            {
                slot[j] = i + 1;
                maxProfit += profit[i];
                break;
            }
        }
    }

    printf("\nJob\tSlot\tProfit\n");

    for(i = 1; i <= maxD; i++)
    {
        if(slot[i] != 0)
        {
            printf("%c\t%d\t%d\n",
                   job[slot[i] - 1],
                   i,
                   profit[slot[i] - 1]);
        }
    }

    printf("\nMaximum Profit = %d\n", maxProfit);

    return 0;
}
