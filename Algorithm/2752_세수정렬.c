#include<stdio.h>

void swap(int *a, int *b)
{
    int temp  = *a;
    *a = *b;
    *b = temp;
}

int arr[3];

int main(void)
{
    for(int i = 0; i < 3; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }

    for(int i = 0; i < 3; i++)
        printf("%d ", arr[i]);
}