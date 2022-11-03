#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
void bubble_sort(int[] ,int );

int main()
{
    int a[100000], n,t1,t2;
    struct timeval tv;
    struct timezone tz;
    printf("Enter a range of you want:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // printf("Enter a element of a[%d]=", i);
        // scanf("%d", &a[i]);
        // a[i] = rand() % 1000;
        a[i]=i+1;
        // a[i]=n-i;
    }
    gettimeofday(&tv,&tz);
    t1=tv.tv_usec;
    bubble_sort(a,n);
    gettimeofday(&tv,&tz);
    t2=tv.tv_usec;
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\ntime complexity of buuble sort:%d\n",t2-t1);

    return 0;
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}