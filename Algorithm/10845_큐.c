#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElementType int

typedef struct _Queue 
{
    int front, rear, size;
    unsigned capacity;
    ElementType* array;
} Queue;

Queue* createQueue(unsigned capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (ElementType*)malloc(queue->capacity * sizeof(ElementType));
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(Queue* queue, int data)
{
    if(isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size++; 
}

ElementType dequeue(Queue* queue)
{
    if(isEmpty(queue))
        return -1;

    int data = queue->array[queue->front];

    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    
    return data;
}

ElementType front(Queue* queue)
{
    if(isEmpty(queue)) 
        return -1;
    return queue->array[queue->front];
}

ElementType back(Queue* queue)
{
    if(isEmpty(queue)) 
        return -1;
    return queue->array[queue->rear];
}

int size(Queue* queue)
{
    return queue->size;
}


int main(void)
{
    Queue* queue = createQueue(10000);

    int n;
    scanf("%d", &n);

    char str[6];

    while(n--)
    {
        scanf("%s", str);

        if(!strcmp(str, "push"))
        {
            int x;
            scanf(" %d", &x);
            enqueue(queue, x);
        }
        else if(!strcmp(str, "pop"))
        {
            printf("%d\n", dequeue(queue));
        }
        else if(!strcmp(str, "size"))
        {
            printf("%d\n", size(queue));
        }
        else if(!strcmp(str, "empty"))
        {
            printf("%d\n", isEmpty(queue));
        }
        else if(!strcmp(str, "front"))
        {
            printf("%d\n", front(queue));
        }
        else if(!strcmp(str, "back"))
        {
            printf("%d\n", back(queue));
        }
    }

    return 0;
}