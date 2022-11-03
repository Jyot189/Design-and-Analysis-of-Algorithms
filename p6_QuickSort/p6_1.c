#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void best(int a[], int first, int last)
{
    if (first < last)
    {
        int m, mid, temp;
        m = (first + last) / 2;
        if (m == first)
        {
            mid = (first + m) / 2;
        }
        else
        {
            mid = (first + m - 1) / 2;
        }

        temp = a[m];
        a[m] = a[mid];
        a[mid] = temp;

        best(a, first, m - 1);
        best(a, m + 1, last);
    }
}

int partition(int a[], int first, int last)
{
    int pivot, i, j, temp;
    pivot = first;
    i = first + 1;
    j = last;
    while (i <= j)
    {

        while (a[i] < a[pivot])
        {
            i++;
        }
        while (a[j] >= a[pivot] && j > first)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[j];
    a[j] = a[pivot];
    a[pivot] = temp;
    return j;
}

void quick_sort(int a[], int first, int last)
{
    int m;
    if (first < last)
    {
        m = partition(a, first, last);
        quick_sort(a, first, m - 1);
        quick_sort(a, m + 1, last);
    }
}

void main()
{
    int a[100000], n, i, t1, t2;
    struct timeval tv;
    struct timezone tz;
    printf("Enter the length: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        // a[i] = rand() % n;          //Avg case
        a[i] = i + 1; // worst case
    }
    // 	best(a, 0, n-1);                   //best case
    gettimeofday(&tv, &tz);
    t1 = tv.tv_usec;
    quick_sort(a, 0, n - 1);
    gettimeofday(&tv, &tz);
    t2 = tv.tv_usec;
    for (i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n Time complexity of Quick Sort:%d", t2 - t1);
}