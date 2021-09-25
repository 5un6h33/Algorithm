#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1002
#define ElementType int

int n, m, v, x, y;
int map[MAX][MAX];
int visited[MAX] = {0, };

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

void reset()
{
    for(int i = 0; i <= n; i++)
        visited[i] = 0;
}

void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 1; i <= n; i++)
    {
        if(map[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int v, Queue* queue)
{
    enqueue(queue, v);
    visited[v] = 1;
    printf("%d ", v);

    while(!isEmpty(queue))
    {
        v = dequeue(queue);

        for(int i = 1; i <= n; i++)
        {
            if(map[v][i] == 1 && visited[i] == 0)
            {
                enqueue(queue, i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main(void)
{
    Queue* queue = createQueue(1002);

    scanf("%d %d %d", &n, &m, &v);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }

    dfs(v);

    printf("\n");

    reset();
    bfs(v, queue);

    return 0;
}