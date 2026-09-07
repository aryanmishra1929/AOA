#include <stdio.h>
 
void merge(int arr[], int len)
{
 
if (len <= 1)
return;
 
int mid = len / 2;
int left[mid];
int right[len - mid];
 
for (int i = 0; i < mid; i++)
{
left[i] = arr[i];
}
 
for (int i = mid; i < len; i++)
{
right[i - mid] = arr[i];
}
 
merge(left, mid);
merge(right, len - mid);
 
int l = 0;
int r = 0;
int re = 0;
int len_left = mid;
int len_right = len - mid;
 
while (l < len_left && r < len_right)
{
if (left[l] < right[r])
{
arr[re] = left[l];
l++;
re++;
}
else
{
arr[re] = right[r];
r++;
re++;
}
}
 
while (l < len_left)
{
arr[re] = left[l];
l++;
re++;
}
 
while (r < len_right)
{
arr[re] = right[r];
r++;
re++;
}
}
 
int main()
{
int len;
printf("Enter the size of arr: ");
scanf("%d", &len);
int arr[len];
printf("Enter elements of the array..");
for( int i = 0; i < len; i++)
{
scanf("%d", &arr[i]);
}
merge(arr, len);
printf("Sorted Array: ");
for (int i = 0; i < len; i++)
{
printf("%d ", arr[i]);
}
return 0;
}
