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

int main(void)
{
    int n, k, tmp;
    Queue* queue = createQueue(5001);

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
        enqueue(queue, i);

    printf("<");

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < k - 1; j++)
        {
            enqueue(queue, dequeue(queue));
        }
        printf("%d, ", dequeue(queue));
    }

    printf("%d", dequeue(queue));
    printf(">");


    return 0;
}