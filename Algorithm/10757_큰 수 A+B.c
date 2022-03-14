#include<stdio.h>
#include<string.h>

void reverse(char arr[])
{
  char temp;
  int len = strlen(arr);
  for(int i = 0; i < len / 2; i++)
  {
    temp = arr[i];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = temp;
  }
}

int main(void)
{
  char a[10002] = {0, };
  char b[10002] = {0, };
  char c[10002] = {0, };
  int len, carry = 0;

  scanf("%s %s", a, b);
  reverse(a);
  reverse(b);

  if(strlen(a) > strlen(b))
    len = strlen(a);
  else
    len = strlen(b);
  
  for(int i = 0; i < len; i++)
  {
    int sum = a[i] - '0' + b[i] - '0' + carry;
    if(sum < 0)
      sum += '0';
    if(sum > 9)
      carry = 1;
    else
      carry = 0;
    c[i] = sum % 10 + '0';
  }
  if(carry == 1)
    c[len] = '1';
  reverse(c);
  printf("%s", c);
  
  return 0;
}
