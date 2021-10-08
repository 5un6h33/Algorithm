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

void push(Stack* stack, int data)
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

void printBot(Stack* stack)
{
    for(int i = 0; i <= stack->top; i++)
        printf("%c", stack->array[i]);
}

int main(void)
{
    int n;
    char ch, cmd;

    Stack* stack_L = createStack(600001);
    Stack* stack_R = createStack(600001);

    while((ch = getchar()) != '\n')
        push(stack_L, ch);

    scanf("%d", &n);

    while(n--)
    {
        scanf(" %c", &cmd);

        if(cmd == 'L')
        {
            if(isEmpty(stack_L))
                continue;
            push(stack_R, pop(stack_L));
        }
        else if(cmd == 'D')
        {
            if(isEmpty(stack_R))
                continue;
            push(stack_L, pop(stack_R));
        }
        else if(cmd == 'B')
        {
            pop(stack_L);
        }
        else if(cmd == 'P')
        {
            scanf(" %c", &ch);
            push(stack_L, ch);
        }
    }

    printBot(stack_L);
    printTop(stack_R);

    return 0;
}