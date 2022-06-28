#include <stdio.h>

int n;
int arr[40001];
int list[40001];

int binarysearch(int left, int right, int target)
{
    int mid;

    while (left < right)
    {
        mid = (left + right) / 2;

        if (list[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int j = 0;
    list[0] = arr[0];
    int i = 1;

    while (i < n)
    {
        if (list[j] < arr[i])
        {
            list[j + 1] = arr[i];
            j += 1;
        }
        else
        {
            int idx = binarysearch(0, j, arr[i]);
            list[idx] = arr[i];
        }
        i += 1;
    }

    printf("%d\n", j + 1);

    return 0;
}
