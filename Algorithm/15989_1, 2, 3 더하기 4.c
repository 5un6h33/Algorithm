#include<stdio.h>

int t, n;
int dp[10001][3];

int main(void)
{
  scanf("%d", &t);
  
  dp[1][0] = 1;
  dp[2][0] = 1;
  dp[2][1] = 1;
  dp[3][0] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;
  
  for(int i = 4; i <= 10000; i++)
  {
    dp[i][0] = 1;
    dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
    dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
  }
  while(t--)
  {
    scanf("%d", &n);
    printf("%d\n",dp[n][0] + dp[n][1] + dp[n][2]);
  }
  
  return 0;
}
