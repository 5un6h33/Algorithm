#include<stdio.h>
#define SIZE 1000001

int arr[SIZE];

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    // make heap system
    for(int i = 1; i < n; i++)
    {
        int c = i;
        do 
        {
            int root = (c - 1) / 2;
            if(arr[root] < arr[c])
            {
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        }
        while(c != 0);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int root = 0;
        int c = 1;
        do
        {
            c = 2 * root + 1;

            if(c < i - 1 && arr[c] < arr[c+1])
                c++;
            if(c < i && arr[root] < arr[c])
            {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            root = c;
        } while (c < i);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    
    return 0;
}