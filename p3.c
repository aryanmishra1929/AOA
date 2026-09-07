#include <stdio.h>


 void swap(int *a, int *b)
 {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

int partition(int A[], int l, int h)
 {
     int pivot = A[l];
     int i = l;
     int j = h;

   while(i < j)
    {
        do
       {
             i++;
         } while(i <= h && A[i] <= pivot);
         do
         {
             j--;
         } while(j >= l && A[j] > pivot);

         if(i < j)
         {
             swap(&A[i], &A[j]);
        }
     }

     swap(&A[l], &A[j]);

     return j;
 }

 void quickSort(int A[], int l, int h)
 {
     if(l < h)
     {
         int j = partition(A, l, h);

         quickSort(A, l, j);

         quickSort(A, j + 1, h);
     }
 }

 void printArray(int A[], int n)
 {
     for(int i = 0; i < n; i++)
         printf("%d ", A[i]);
 }

 int main()
 {
     int A[] = {50, 70, 60, 90, 40, 80, 10};
     int n = 7;

     printf("Original Array: ");
     printArray(A, n);

     quickSort(A, 0, n);

     printf("\nSorted Array: ");
     printArray(A, n);

     return 0;
 }
