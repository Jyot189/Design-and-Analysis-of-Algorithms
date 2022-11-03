#include <stdio.h>
#include <stdlib.h>
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
int main()
{
    int a[100000], n, i;
    printf("Enter a array size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter a element a[%d]:", i + 1);
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100000];
    while (i <= mid && j <= high)
    {

        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++, k++;
        }
        else
        {
            b[k] = a[j];
            j++, k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++, k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++, k++;
    }
    for (int m = low; m <= high; m++)
    {
        a[m] = b[m];
    }
}