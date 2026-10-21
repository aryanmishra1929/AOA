#include <stdio.h>
 
int main()
{
    int n, i, j, k;
    int a[10][10];
 
    printf("Enter number of vertices: ");
    scanf("%d", &n);
 
    printf("Enter cost matrix (-1 for no edge):\n");
 
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
 
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][k] != -1 && a[k][j] != -1)
                {
                    if (a[i][j] == -1 ||
                        a[i][k] + a[k][j] < a[i][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
 
    printf("\\nShortest distance matrix:\\n");
 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
 
        printf("\\n");
    }
 
    return 0;
}
