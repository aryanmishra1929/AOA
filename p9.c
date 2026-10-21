#include <stdio.h>

int graph[10][10], color[10];
int n, m;

int isSafe(int v, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoring(int v)
{
    if (v == n)
        return 1;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (graphColoring(v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if (graphColoring(0))
    {
        printf("Graph can be colored.\n");

        for (int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    }
    else
    {
        printf("Graph cannot be colored with %d colors.\n", m);
    }

    return 0;
}
