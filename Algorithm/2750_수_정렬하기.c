#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int arr[1001];

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}