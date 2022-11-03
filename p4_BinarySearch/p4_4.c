#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void binary_search(int [],int,int,int,int);
void linear_search(int [],int,int);
int main(){
    int n,a[10000],i,no,t1,t2;
    struct timeval tv;
    struct timezone tz;
    printf("enter a size of array:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        a[i]=i+1;
    }
     no=1 ; //Best Case
    // no = rand()%n + 1;   //Average Case          
    // no=n+1; //Worste Case  

    gettimeofday(&tv,&tz);
    t1=tv.tv_usec;
    linear_search(a,n,no);
    // binary_search(a,0,n-1,no,n);
    gettimeofday(&tv,&tz);
    t2=tv.tv_usec;

    printf("Time complexity of Linear search:%d\n",t2-t1);
    return 0;
}
void binary_search(int a[],int low,int high,int no,int n){
    int mid;
    mid=(low+high)/2;
    if((mid==0 || mid==n-1) && (a[mid]!=no)){
        printf("Number %d not found\n",no);
    }
    else if(a[mid]==no){
        printf("Number %d found at index %d\n",no,mid);
    }else if(no>a[mid]){
        low=mid+1;
        binary_search(a,low,high,no,n);
    }
    else{
        high=mid-1;
        binary_search(a,low,high,no,n);
    }
}

void linear_search(int a[],int n,int no){
    int i;

    for(i=0;i<n;i++){
        if(a[i]==no){
            printf("your number index no is:%d\n",i);
            break;
        }
        if(i==n-1){
            printf("element is not found\n");
        }
    }


}