#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int makingChange(int a[], int n, int amount)
{
    int i, j;
    int c[n+1][amount+1];
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<amount+1; j++)
        {
            if(i == 0){
                c[i][j] = INT_MAX;
                continue;
            }
            if(j==0){
                c[i][j] = 0;
                continue;
            }
            int m1 = c[i-1][j];
            int m2;
            if(j - a[i-1] >= 0){
                m2 = c[i][j- a[i-1]];
            }
            else{
                m2 = INT_MAX;
            }
            c[i][j] = (m1 < m2) ? m1 : m2 + 1;
            printf("%d, ",c[i][j]);
        }
        printf("\n");
    }
    return c[n][amount];
}

void main()
{
    int n, amount, change;
    n=0;
    int a[30];
    printf("Enter the coins: ");
    int coin = -1;
    while(coin != 0){
        scanf("%d", &coin);
        if(coin == 0){
            break;
        }
        a[n] = coin;
        n++;
    }
    printf("Enter the amount: ");
    scanf("%d", &amount);
    change=-1;
    change = makingChange(a, n, amount);
    printf("\nchange: %d", change);
}