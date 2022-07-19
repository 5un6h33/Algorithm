#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 2000000000

int N, S, start, end, sum, min = INF;
int arr[100001];

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    while (start <= end)
    {
        if (sum >= S)
        {
            min = MIN(min, end - start);
            sum -= arr[start++];
        }
        else if (end == N)
            break;
        else
            sum += arr[end++];
    }

    if (min == INF)
        printf("0\n");
    else
        printf("%d\n", min);

    return 0;
}