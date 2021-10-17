#include<stdio.h>

int num = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int* data, int start, int end)
{
    if(start >= end)
        return;
    int pivot = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    while(i <= j)
    {
        while(i <= end && data[i] >= data[pivot])
            i++;
        while(start < j && data[pivot] >= data[j])
            j--;
        if(i > j)
        {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main(void)
{
    quickSort(data, 0, num-1);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    
    return 0;
}