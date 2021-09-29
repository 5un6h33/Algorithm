// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// #define ElementType int

// typedef struct _Stack
// {
//     int top;
//     unsigned capacity;
//     ElementType* array;
// } Stack;

// Stack* createStack(unsigned capacity)
// {
//     Stack* stack = (Stack*)malloc(sizeof(Stack));
//     stack->capacity = capacity;
//     stack->top = -1;
//     stack->array = (ElementType*)malloc(stack->capacity * sizeof(ElementType));
//     return stack;
// }

// int isFull(Stack* stack)
// {
//     return stack->top == stack->capacity -1;
// }

// int isEmpty(Stack* stack)
// {
//     return stack->top == -1;
// }

// void push(Stack* stack, ElementType data)
// {
//     if(isFull(stack))
//         return;
//     stack->array[++stack->top] = data;
// }

// ElementType pop(Stack* stack)
// {
//     if(isEmpty(stack))
//         return -1;
//     return stack->array[stack->top--];
// }

// ElementType top(Stack* stack)
// {
//     if(isEmpty(stack))
//         return -1;
//     return stack->array[stack->top];
// }

// void printTop(Stack * stack)
// {
//     while(stack->top != -1)
//         printf("%c", stack->array[stack->top--]);
// }


// int arr[1000001];
// int ans[1000001];

// int main(void)
// {
//     int n;
//     Stack* stack;
//     stack = createStack(1000001);

//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     for(int i = n - 1; i >= 0; i--)
//     {
//         while(!isEmpty(stack) && top(stack) <= arr[i])
//             pop(stack);
//         if(isEmpty(stack)) ans[i] = -1;
//         else ans[i] = top(stack);

//         push(stack, arr[i]);
//     }

//     for(int i = 0; i < n; i++)
//         printf("%d ", ans[i]);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000001

int err = -1;

typedef int element;

typedef struct {
    element data[SIZE];
    int top;
} Stack;

void createStack(Stack* stack)
{
    stack->top = -1;
}

int isEmpty(Stack* stack)
{
    return (stack->top == -1);
}

int isFull(Stack* stack)
{
    return (stack->top == (SIZE - 1));
}

void push(Stack* stack, element item)
{
    if(isFull(stack))
        return;
    stack->data[++stack->top] = item;
}

element pop(Stack* stack)
{
    if(isEmpty(stack))
        return err;
    return stack->data[stack->top--];
}

element top(Stack* stack)
{
    if(isEmpty(stack))
        return err;
    return stack->data[stack->top];
}


int arr[1000001];
int ans[1000001];

int main(void)

{
    int n;
    Stack stack;
    createStack(&stack);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = n - 1; i >= 0; i--)
    {
        while(!isEmpty(&stack) && top(&stack) <= arr[i])
            pop(&stack);
        if(isEmpty(&stack)) ans[i] = -1;
        else ans[i] = top(&stack);

        push(&stack, arr[i]);
    }

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}