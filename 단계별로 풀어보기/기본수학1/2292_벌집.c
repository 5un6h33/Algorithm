#include <stdio.h>

int main()
{
    int N, n=1;
    
    scanf("%d", &N);
    if(N==1) 
    {
        printf("%d", n);
        return 0;
    }
    while(1){
        if(3*n*n -3*n + 2 <= N && 3*n*n + 3*n + 1 >= N)
        {
            n += 1;
            printf("%d", n);
            break;
        }
        n++;
    }
    return 0;
}