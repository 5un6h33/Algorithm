#include<stdio.h>

int DP[1000001];

int min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 2; i <= n; ++i)
    {
        DP[i] = DP[i-1] + 1;
        if(i % 2 == 0)
            DP[i] = min(DP[i], DP[i/2] + 1);
        if(i % 3 == 0)
            DP[i] = min(DP[i], DP[i/3] + 1);
    }

    printf("%d", DP[n]);

    return 0;
}