#include <stdio.h>
 
int a[10], n, target;
 
int subset(int i, int sum)
{
    if (sum == target)
        return 1;
 
    if (i == n || sum > target)
        return 0;
 
    if (subset(i + 1, sum + a[i]))
    {
        printf("%d ", a[i]);
        return 1;
    }
 
    return subset(i + 1, sum);
}
 
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
 
    printf("Enter target sum: ");
    scanf("%d", &target);
 
    printf("Subset: ");
 
    if (!subset(0, 0))
        printf("No subset exists");
 
    return 0;
}
