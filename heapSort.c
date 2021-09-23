// // 상향식
// #include<stdio.h>

// int number = 10;
// int heap[10] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};

// int main(void)
// {
//     // 힙 구성
//     for(int i = 1; i < number; i++)
//     {
//         int c = i;
//         do
//         {
//             int root = (c - 1) / 2;
//             if(heap[root] < heap[c])
//             {
//                 int temp = heap[root];
//                 heap[root] = heap[c];
//                 heap[c] = temp;
//             }
//             c = root;
//         } while (c != 0);
//     }

//     // 크기를 줄여가며 반복적으로 힙 구성   
//     for(int i = number - 1; i >= 0; i--)
//     {
//         for(int i = 0; i < number; i++)
//             printf("%d ", heap[i]);
//         printf("\n");
//         int temp = heap[0];
//         heap[0] = heap[i];
//         heap[i] = temp;
//         int root = 0;
//         int c = 1;
//         do
//         {
//             c = root * 2 + 1;
//             // 루트보다 자식이 크다면 교환
//             if(c < i - 1 && heap[c] < heap[c+1])
//                 c++;
//             if(c < i && heap[root] < heap[c])
//             {
//                 temp = heap[root];
//                 heap[root] = heap[c];
//                 heap[c] = temp;
//             }
//             root = c;
//         } while (c < i);
//     }

    

//     return 0;
// }

// 하향식

#include<stdio.h>

int number = 10;
int heap[10] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};

int main(void)
{
    // 힙 구성
    for(int i = 1; i < number; i++)
    {
        int c = i;
        do
        {
            int root = (c - 1) / 2;
            if(heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    // 크기를 줄여가며 반복적으로 힙 구성   
    for(int i = number - 1; i >= 0; i--)
    {
        for(int i = 0; i < number; i++)
            printf("%d ", heap[i]);
        printf("\n");
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do
        {
            root = (c - 1) / 2;
            // 루트보다 자식이 크다면 교환

            if(heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }

            if(c < i - 1 && heap[c] < heap[c+1])
                c++;
            if(c < i && heap[root] < heap[c])
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c != 0);
    }

    return 0;
}