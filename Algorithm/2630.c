#include <stdio.h>

int white, blue;
int paper[129][129];

int check(int x, int y, int n)
{
    int start = paper[x][y];
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (start != paper[i][j])
                return 0;
    return 1;
}

void divide(int x, int y, int n)
{
    if (check(x, y, n))
    {
        if (paper[x][y] == 0)
            white++;
        else
            blue++;
        return;
    }
    int size = n / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            divide(x + size * i, y + size * j, size);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &paper[i][j]);

    divide(0, 0, n);

    printf("%d\n%d\n", white, blue);

    return 0;
}
