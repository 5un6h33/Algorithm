#include<stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(b - 45 < 0 && a == 0) printf("%d %d", 23, 60+(b-45));
    else if(b - 45 < 0) printf("%d %d", a-1, 60+(b-45));
    else printf("%d %d", a, b-45);
    
    return 0;
}