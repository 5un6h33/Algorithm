#include <stdio.h>
#include <string.h>
#define MOD 10007

int dp[1001][1001];

int binomial(int n, int k)
{
    if (dp[n][k] != -1)
        return dp[n][k];
    if (k == 0 || k == n)
        return dp[n][k] = 1;
    return dp[n][k] = (binomial(n - 1, k - 1) + binomial(n - 1, k)) % MOD;
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", binomial(n, k));
    return 0;
}
