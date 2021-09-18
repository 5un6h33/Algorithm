#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagArrayStack
{
    int Capacity;
    int Top;
    Node * Nodes;
} ArrayStack;

void stack(ArrayStack** Stack, int Capacity)
{
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

void destroy(ArrayStack* Stack)
{
    free(Stack->Nodes);
    free(Stack);
}

void push(ArrayStack* Stack, ElementType Data)
{
    int Position = Stack->Top;

    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}

int size(ArrayStack* Stack)
{
    return Stack->Top;
}

int empty(ArrayStack* Stack)
{
    return (Stack->Top == 0);
}

ElementType top(ArrayStack* Stack)
{
    if(empty(Stack)) return -1;
    int Position = Stack->Top - 1;

    return Stack->Nodes[Position].Data;
}

ElementType pop(ArrayStack* Stack)
{
    if(empty(Stack)) return -1;
    int Position = --(Stack->Top);
    
    return Stack->Nodes[Position].Data;
}

int main(void)
{
    int n, data;
    char str[6];

    ArrayStack* Stack = NULL;

    stack(&Stack, 100001);

    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%s", str);

        if(!strcmp(str, "push"))
        {
            scanf("%d", &data);
            push(Stack, data);
        }
        else if(!strcmp(str, "pop"))
        {
            printf("%d\n", pop(Stack));
        }
        else if(!strcmp(str, "size"))
        {
            printf("%d\n", size(Stack));
        }
        else if(!strcmp(str, "empty"))
        {
            printf("%d\n", empty(Stack));
        }
        else if(!strcmp(str, "top"))
        {
            printf("%d\n", top(Stack));
        }
    }


    return 0;
}