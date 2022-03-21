#include <stdio.h>

long long n, b;
long long A[5][5];
long long temp[5][5];
long long ans[5][5];

void matrixMul(long long x[5][5], long long y[5][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++)
                temp[i][j] += (x[i][k] * y[k][j]);
            temp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = temp[i][j];
}

int main(void)
{
    scanf("%lld %lld", &n, &b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%lld", &A[i][j]);
        ans[i][i] = 1;
    }

    while (b > 0)
    {
        if (b % 2 == 1)
            matrixMul(ans, A);
        matrixMul(A, A);
        b /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%lld ", ans[i][j]);
        printf("\n");
    }

    return 0;
}
