#include <stdio.h>

int main()
{
    int obj;
    int max_capacity;

    printf("Enter number of objects: ");
    scanf("%d", &obj);

    printf("Enter max capacity: ");
    scanf("%d", &max_capacity);

    int profit[obj];
    int weight[obj];

    for (int i = 0; i < obj; i++)
    {
        printf("Enter the profit of the object (%d): ", i + 1);
        scanf("%d", &profit[i]);

        printf("Enter the weight of the object (%d): ", i + 1);
        scanf("%d", &weight[i]);
    }

    float ratio[obj];
    int visited[obj];

    for (int i = 0; i < obj; i++)
    {
        ratio[i] = (float)profit[i] / weight[i];
        visited[i] = 0;
    }

    int occupied_capacity = 0;
    float profit_gain = 0.0;

    while (occupied_capacity < max_capacity)
    {
        int max_index = -1;
        float max_ratio = -1.0;

        for (int i = 0; i < obj; i++)
        {
            if (!visited[i] && ratio[i] > max_ratio)
            {
                max_ratio = ratio[i];
                max_index = i;
            }
        }

        if (max_index == -1)
        {
            break;
        }

        visited[max_index] = 1;

        if (occupied_capacity + weight[max_index] <= max_capacity)
        {
            occupied_capacity += weight[max_index];
            profit_gain += profit[max_index];
        }
        else
        {
            int remaining_capacity = max_capacity - occupied_capacity;
            profit_gain += ratio[max_index] * remaining_capacity;
            occupied_capacity = max_capacity;
        }
    }

    printf("\nMaximum Profit = %.2f\n", profit_gain);

    return 0;
}
