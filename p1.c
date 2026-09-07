#include <stdio.h>

void insertionSort(int A[], int n)
{
    int i, j, x;

    for(i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];

        while(j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = x;
    }
}

void insertKey(int A[], int *n, int key)
{
    int j = *n - 1;

    while(j >= 0 && A[j] > key)
    {
        A[j + 1] = A[j];
        j--;
    }

    A[j + 1] = key;
    (*n)++;
}

int main()
{
    int A[100], n, i, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    insertionSort(A, n);

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n\nEnter key element to insert: ");
    scanf("%d", &key);

    insertKey(A, &n, key);

    printf("\nArray after inserting key:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
} 
