#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HeapSort(int [],int);
void Build_max_heap(int [],int);
void Max_Heapify(int [],int ,int);
int main()
{
    int a[1000],n;

    printf("Enter a array size: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter a element a[%d]:", i + 1);
        scanf("%d", &a[i]);
    }

    HeapSort(a,n);

    printf("Heap Sort:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void HeapSort(int a[],int n)
{
    int i;
    Build_max_heap(a,n);
     for (i = n-1; i > 0; i--)
    {
        int temp = a[0];
        a[0]=a[i];
        a[i]=temp;
        Max_Heapify(a, 0,i-1);
    }
}

void Build_max_heap(int a[],int n)
{
    for (int i = ((n) / 2)-1; i >= 0; i--)
    {
        Max_Heapify(a, i,n-1);
    }
}

void Max_Heapify(int a[], int i,int l)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if ((left <= l) && a[left] > a[i])
    {
        largest = left;
    }
    if ((right <= l) && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        Max_Heapify(a, largest,l);
    }
}
