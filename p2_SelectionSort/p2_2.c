#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
void selection_sort(int[],int);
int main()
{
    int n, a[100000],t1,t2;
    struct timeval tv;
    struct timezone tz;
    printf("enter a array size:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        // printf("Enter a array element a[%d]:", i + 1);
        // scanf("%d", &a[i]);
        // a[i]=rand()%1000;
        a[i]=i+1;
        // a[i]=n-i;
    }
    gettimeofday(&tv,&tz);
    t1=tv.tv_usec;
    selection_sort(a,n);
    gettimeofday(&tv,&tz);
    t2=tv.tv_usec;
     for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("time complexity is selection:%d\n",t2-t1);
    return 0;
}

void selection_sort(int a[],int n){
    for(int i = n-1; i >0; i--){
        int no=a[i];
        int max=i;
        for(int j = 0; j <i;j++){
            if(a[max]<a[j]){
                max=j;
            }
        }
        if(max!=i){
            a[i]=a[max];
            a[max]=no;
        }
    }

}