#include <stdio.h>

int m1[101][101];
int m2[101][101];
int m3[101][101];

int main(void)
{
    // freopen("input.txt", "r", stdin);
    int n, m, k, sum;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &m1[i][j]);

    scanf("%d %d", &m, &k);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &m2[i][j]);

    for (int l = 0; l < n; l++)
        for (int j = 0; j < k; j++)
            for (int i = 0; i < m; i++)
                m3[l][j] += m1[l][i] * m2[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            printf("%d ", m3[i][j]);
        printf("\n");
    }

    return 0;
}
