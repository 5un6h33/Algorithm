#include<stdio.h>
#include<string.h>

int main(void)
{
    int n, start, end;
    char *p;
    char str[1001];

    scanf("%d", &n);
    
    while(n--)
    {
        start = end = 0;
        fflush(stdin);
        fgets(str, sizeof(str)-1, stdin);
        if((p=strchr(str,'\n')) != NULL) *p = ' ';
        // printf("%lu", strlen(str));
        for(int i = 0; i <= strlen(str); i++)
        {
            if(str[i] == 0x20 || str[i] == 0x00)
            {
                for(int k = end-1; k >= start; k--)
                    printf("%c", str[k]);
                printf(" ");
                end = start = i + 1;
            }
            else 
                end++;
        }
        printf("\n");
    }

    return 0;
}