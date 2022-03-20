#include <stdio.h>
#define MOD 1000000007

int n, k;

long long pow(long long a, long long b)
{
    if (b == 0)
        return 1;
    if (b % 2 > 0)
        return (pow(a, b - 1) * a) % MOD;
    long long half = pow(a, b / 2) % MOD;
    return (half * half) % MOD;
}

int main(void)
{
    long long a = 1, b = 1; //  a = n!, b = k!(n - k)!
    scanf("%d %d", &n, &k);
    for (long long i = 1; i <= n; i++)
    {
        a *= i;
        a %= MOD;
    }
    for (long long i = 1; i <= k; i++)
    {
        b *= i;
        b %= MOD;
    }
    for (long long i = 1; i <= n - k; i++)
    {
        b *= i;
        b %= MOD;
    }
    long long b2 = pow(b, MOD - 2); // b2 = b^(MOD - 2)
    long long ans = a * b2;
    ans %= MOD;
    printf("%lld\n", ans);

    return 0;
}
