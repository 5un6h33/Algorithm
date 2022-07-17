#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
#define INF 2000000000

int N, start, end, min, sum;
int arr[MAX];
int answer[2];

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    qsort(arr, N, sizeof(int), compare);

    start = 0;
    end = N - 1;
    min = INF;

    while (start < end)
    {
        sum = arr[start] + arr[end];

        if (min > abs(sum))
        {
            min = abs(sum);
            answer[0] = arr[start];
            answer[1] = arr[end];

            if (sum == 0)
                break;
        }

        if (sum < 0)
            start++;
        else
            end--;
    }

    printf("%d %d\n", answer[0], answer[1]);

    return 0;
}