#include <stdio.h>

struct Item
{
    int value;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item items[], int n)
{
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
        {
            break;
        }

        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            capacity = 0;
        }
    }

    return totalValue;
}

int main()
{
    struct Item items[] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    for (int i = 0; i < n; i++)
    {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
