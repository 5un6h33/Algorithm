#include <stdio.h>

int n, s, cnt, sum;
int arr[21];

int main(void)
{
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for(int i = 1; i < (1 << n); i++)
  {
    sum = 0;
    for(int j = 0; j < n; j++)
    {
      if(i & (1 << j))
        sum += arr[j];
    }
    if(sum == s)
      cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}
