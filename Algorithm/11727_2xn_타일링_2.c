#include<stdio.h>

int arr[1001];

int dp(int n)
{
    if(n == 1)
        return 1;
    if(n == 2) 
        return 3;
    if(arr[n] != 0) return arr[n];
    return arr[n] = (dp(n-1) + dp(n-2) * 2) % 10007;   
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", dp(n));

    return 0;
}