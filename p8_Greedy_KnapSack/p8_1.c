#include <stdio.h>
#include <string.h>
struct knapsack
{
    int v;
    int w;
    float vw;
};
void i_weightSort(struct knapsack s[], int);
void d_valueSort(struct knapsack s[], int);
void d_vwSort(struct knapsack s[], int);
void i_weight(struct knapsack s[], int, int);
void d_value(struct knapsack s[], int, int);
void d_vw(struct knapsack s[], int,int);
int main()
{
    int n, i, totalweight;
    struct knapsack s[50];
    printf("enter a no item:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter a weight:");
        scanf("%d", &s[i].w);
        printf("enter a value:");
        scanf("%d", &s[i].v);
        s[i].vw=(float)s[i].v/(float)s[i].w;
    }
    printf("enter a total weight:");
    scanf("%d", &totalweight);
    i_weight(s, totalweight, n);
    printf("\n");
    d_value(s, totalweight, n);
    printf("\n");
    d_vw(s, totalweight,n);
    return 0;
}

void i_weightSort(struct knapsack s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].w > s[j + 1].w)
            {
                struct knapsack temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void i_weight(struct knapsack s[], int totalweight, int n)
{
    int i = 0, j = 0, weight = 0;
    float value = 0.0;

    i_weightSort(s, n);

    while (weight <= totalweight)
    {
        if (weight == totalweight || n == j)
        {
            break;
        }
        if (weight + s[j].w <= totalweight)
        {
            value = (float)s[j].v + value;
            weight = weight + s[j].w;
            j++;
        }
        else if (totalweight - weight < s[j].w)
        {
            float temp = ((float)totalweight - (float)weight) / ((float)s[j].w);
            value = ((float)s[j].v * temp) + value;
            weight = weight + (s[j].w * temp);
            break;
        }
    }
    printf("increasing weight by value :%f", value);
}

void d_valueSort(struct knapsack s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].v < s[j + 1].v)
            {
                struct knapsack temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
void d_value(struct knapsack s[], int totalweight, int n)
{
    int i = 0, j = 0, weight = 0;
    float value = 0.0;
    d_valueSort(s, n);

    while (weight <= totalweight)
    {
        if (weight == totalweight || n == j)
        {
            break;
        }
        if (weight + s[j].w <= totalweight)
        {
            value = (float)s[j].v + value;
            weight = weight + s[j].w;
            j++;
        }
        else if (totalweight - weight < s[j].w)
        {
            float temp = ((float)totalweight - (float)weight) / ((float)s[j].w);
            value = ((float)s[j].v * temp) + value;
            weight = weight + (s[j].w * temp);
            break;
        }
    }
    printf("decreasing by value: %f", value);
}

void d_vwSort(struct knapsack s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].vw < s[j + 1].vw)
            {
                struct knapsack temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
void d_vw(struct knapsack s[], int totalweight, int n){
    int i = 0, j = 0, weight = 0;
    float value = 0.0;
    d_vwSort(s, n);

    while (weight <= totalweight)
    {
        if (weight == totalweight || n == j)
        {
            break;
        }
        if (weight + s[j].w <= totalweight)
        {
            value = (float)s[j].v + value;
            weight = weight + s[j].w;
            j++;
        }
        else if (totalweight - weight < s[j].w)
        {
            float temp = ((float)totalweight - (float)weight) / ((float)s[j].w);
            value = ((float)s[j].v * temp) + value;
            weight = weight + (s[j].w * temp);
            break;
        }
    }
    printf("decreasing by vw: %f", value);
}