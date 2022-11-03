#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int weight[], int value[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}
int main()
{
    int value[] = {1, 6, 18, 22, 28};
    int weight[] = {1, 2, 5, 6, 7};
    int W;
    printf("Enter a Total weight:");
    scanf("%d", &W);
    int n = sizeof(value) / sizeof(value[0]);
    printf("Total profit:%d", knapSack(W, weight, value, n));
    return 0;
}
