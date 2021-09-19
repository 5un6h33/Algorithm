#include<stdio.h>
#include<string.h>

char str[1001];
char stack[1001];

int main(void)
{
    int n, j = 0;
    char *p;
    scanf("%d", &n);

    while(n--)
    {
        fflush(stdin);
        fgets(str, sizeof(str)-1, stdin);
        // if((p=strchr(str,'\n')) != NULL) *p = '\0';
        // printf("%lu", strlen(str));
        for(int i = 0; i < strlen(str) - 1; i++)
        {
            if(str[i] == 0x20 || str[i] == '\n')
            {
                for(int k = strlen(stack) - 1; k >= 0; k--)
                {
                    printf("%c", stack[k]);
                }
                printf(" ");
                j = 0;
            }
            else 
            {
                stack[j] = str[i];
                j++;
            }
        }
        printf("\n");
    }

    return 0;
}