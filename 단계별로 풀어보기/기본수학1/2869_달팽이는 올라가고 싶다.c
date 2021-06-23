#include<stdio.h>

int main(void)
{
    unsigned int A, B, V, N;
    scanf("%d %d %d", &A, &B, &V);
    if((V - A) % (A - B) != 0)
        N = 1 + (V - A) / (A - B) + 1;
    else
        N = 1 + (V - A) / (A - B);
    printf("%d", N);
    return 0;
}