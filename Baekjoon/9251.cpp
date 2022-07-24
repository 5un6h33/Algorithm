#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

char s1[1002];
char s2[1002];
int dp[1001][1001], i, j;

int main()
{
    scanf("%s %s", s1 + 1, s2 + 1);
    for (i = 1; s1[i]; i++)
        for (j = 1; s2[j]; j++)
            dp[i][j] = MAX(dp[i][j - 1], MAX(dp[i - 1][j], dp[i - 1][j - 1] + (s1[i] == s2[j])));
    printf("%d\n", dp[i - 1][j - 1]);
    return 0;
}