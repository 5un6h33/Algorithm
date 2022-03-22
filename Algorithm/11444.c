#include <stdio.h>
#define MOD 1000000007

long long n;
long long A[2][2] = {{1, 1}, {1, 0}};
long long temp[2][2];
long long ans[2][2] = {{1, 0}, {0, 1}};

void matrixMul(long long x[2][2], long long y[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < 2; k++)
                temp[i][j] += (x[i][k] * y[k][j]);
            temp[i][j] %= MOD;
        }
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            x[i][j] = temp[i][j];
}

int main(void)
{
    scanf("%lld", &n);

    while (n > 0)
    {
        if (n % 2 == 1)
            matrixMul(ans, A);
        matrixMul(A, A);
        n /= 2;
    }

    printf("%lld", ans[0][1]);

    return 0;
}
