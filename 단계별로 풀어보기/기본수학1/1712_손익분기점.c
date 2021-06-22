#include <stdio.h>

int main()
{
    int A, B, C, N; 
    scanf("%d %d %d", &A, &B, &C);
    if(B == C || C - B < 0)
    {
        printf("-1");
    }
    else
    {
        N = A / (C - B) + 1;
        printf("%d", N);
    }

    return 0;
}