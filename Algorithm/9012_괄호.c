#include<stdio.h>
#include<string.h>
#define SIZE 50

int main(void)
{
    int n, top;
    char str[SIZE];
    scanf("%d", &n);

    while(n--)
    {
        top = 0;
        scanf("%s", str);
        
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == '(')
                top++;
            else if(str[i] == ')')
                top--;
            if(top < 0)
                break;
        }

        if(top == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}