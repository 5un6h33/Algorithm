#include<stdio.h>

int main(void)
{
  int t, n;
  int dp[10001];

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  
  for(int i = 4; i <= 10000; i++)
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    printf("%d\n", dp[n]);
  }
  
  return 0;
}
