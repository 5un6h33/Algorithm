#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ElementType char

typedef struct _Stack
{
    int top;
    unsigned capacity;
    ElementType* array;
} Stack;

Stack* createStack(unsigned capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (ElementType*)malloc(stack->capacity * sizeof(ElementType));
    return stack;
}

int isFull(Stack* stack)
{
    return stack->top == stack->capacity -1;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, ElementType data)
{
    if(isFull(stack))
        return;
    stack->array[++stack->top] = data;
}

ElementType pop(Stack* stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

ElementType peak(Stack* stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

void printTop(Stack * stack)
{
    while(stack->top != -1)
        printf("%c", stack->array[stack->top--]);
}

char str[100001];

int main(void)
{
    Stack* stack = createStack(100001);
    gets(str);
    int n = strlen(str);
    int stack_flag = 1;
    str[n] = 0x20;

    for(int i = 0; i <= n; i++)
    {
        if(str[i] == '>')
        {
            printf("%c", str[i]);
            stack_flag = 1;
        }
        else if(str[i] == '<')
        {
            printTop(stack);
            printf("%c", str[i]);
            stack_flag = 0;
        }
        else if(stack_flag)
        {
            if(str[i] == 0x20)
            {
                printTop(stack);
                printf(" ");
            }
            else
                push(stack, str[i]);
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}