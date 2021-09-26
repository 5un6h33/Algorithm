#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define ElementType int

typedef struct _duqueueType
{
    int rear, front, size;
    unsigned capacity;
    ElementType *data;
} Deque;

Deque* createDeque(unsigned capacity)
{
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->capacity = capacity;
    deque->front = deque->rear = 0;

    deque->data = (ElementType*)malloc(sizeof(ElementType) * deque->capacity);
    return deque;
}

int isEmpty(Deque* deque)
{
    return (deque->front == deque->rear);
}

int isFull(Deque* deque)
{
    return (((deque->rear + 1) % deque->capacity) == deque->front);
}

ElementType back(Deque* deque)
{
    if(isEmpty(deque))
        return ERROR;
    return deque->data[deque->rear];
}

ElementType front(Deque* deque)
{
    if(isEmpty(deque))
        return ERROR;
    return deque->data[(deque->front + 1) % deque->capacity];
}

void push_front(Deque* deque, ElementType data)
{
    if(isFull(deque))
        return;
    deque->data[deque->front] = data;
    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
}

void push_back(Deque* deque, ElementType data)
{
    if(isFull(deque))
        return;
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->data[deque->rear] = data;
}

ElementType pop_front(Deque* deque)
{
    if(isEmpty(deque))
        return ERROR;
    ElementType tmp = front(deque);
    deque->front = (deque->front + 1) % deque->capacity;
    return tmp;
}

ElementType pop_back(Deque* deque)
{
     if(isEmpty(deque))
        return ERROR;
    ElementType tmp = back(deque);
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    return tmp;
}

int size(Deque* deque)
{
    return (deque->rear - deque->front + deque->capacity) % deque->capacity;
}

int main(void)
{
    Deque* deque = createDeque(100001);

    int n, x;
    scanf("%d", &n);

    char str[11];

    while(n--)
    {
        scanf("%s", str);

        if(!strcmp(str, "push_front"))
        {
            scanf(" %d", &x);
            push_front(deque, x);
        }
        else if(!strcmp(str, "push_back"))
        {
            scanf(" %d", &x);
            push_back(deque, x);
        }
        else if(!strcmp(str, "pop_front"))
        {
            printf("%d\n", pop_front(deque));
        }
        else if(!strcmp(str, "pop_back"))
        {
            printf("%d\n", pop_back(deque));
        }
        else if(!strcmp(str, "size"))
        {
            printf("%d\n", size(deque));
        }
        else if(!strcmp(str, "empty"))
        {
            printf("%d\n", isEmpty(deque));
        }
        else if(!strcmp(str, "front"))
        {
            printf("%d\n", front(deque));
        }
        else if(!strcmp(str, "back"))
        {
            printf("%d\n", back(deque));
        }
    }

    return 0;
}