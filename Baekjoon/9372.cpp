#include <stdio.h>

int T, N, M;

int main(void)
{
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < M; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
        }

        printf("%d\n", N - 1);
    }

    return 0;
}