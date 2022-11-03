#include<stdio.h>
#include<stdlib.h>

void makingChange(int [],int [],int);
int main(){
    int i=0,j=0,totalamount,a[50],c[50],coin;

    while(c[j++]!=0){
        printf("Enter a coins:");
        scanf("%d",&c[j]);
    }
    
    printf("Enter a amount: ");
    scanf("%d",&totalamount);

    makingChange(a,c,totalamount);

    while(a[i]!=0){
        printf("%d ",a[i]);
        i++;
    }
    return 0;
}

void makingChange(int a[],int c[],int totalamount){
    int amount=0,i=0,j=0;

    while(amount<=totalamount){
        if(amount==totalamount){
            a[i]=0;
            break;
        }
        if(amount+c[j]<=totalamount){
            amount=amount+c[j];
            a[i]=c[j];
            i++;
        }else{
            j++;
        }

    }
}
