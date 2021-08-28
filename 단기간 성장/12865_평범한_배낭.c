#include<stdio.h>

int main(void)
{
    int n, k, max = 0, temp = 0, w;
    int arr[100][2];

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", arr[i][0], arr[i][1]);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            w = 0;
            temp = 0;

            if(i == j && k >= arr[j][0]) 
            {
                w += arr[j][0];
                temp += arr[j][1];
            }
            if()
        }
    }

    return 0;
}