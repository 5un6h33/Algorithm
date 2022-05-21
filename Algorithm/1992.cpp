#include <cstdio>

int n;
int map[65][65];

int check(int start, int end, int num)
{
    int temp = map[start][end];
    for(int i = start; i < start + num; i++)
        for(int j = end; j < end + num; j++)
            if(map[i][j] != temp)
                return 0;
    return 1;
}

void divide(int start, int end, int num)
{
    if(check(start, end, num))
        printf("%d", map[start][end]);
    else
    {
        int size = num >> 1;
        printf("(");
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                divide(start + size * i, end + size * j, size);
        printf(")");
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%1d", &map[i][j]);
    
    divide(0, 0, n);
        
    
    return 0;
}
