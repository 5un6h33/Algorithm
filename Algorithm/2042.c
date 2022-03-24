#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long *tree;
    long long n, m, k;  // 숫자 개수, 변경 횟수, 구간 합을 구하는 횟수
    long long oper;     // 1이면 숫자 교체, 2이면 구간 합 구하기
    long long from, to; // 변경할 숫자의 위치, 해당 위치에 들어갈 새로운 숫자
    long long result;

    scanf("%lld %lld %lld", &n, &m, &k);
    tree = (long long *)malloc(sizeof(long long) * (4 * n)); // 메모리 제한을 생각해서 동적 할당을 사용

    long long base = 2 * n; // 제일 아래 노드들과 상위 노드들을 나눠주는 기준점, 여유롭게 2n으로 잡음

    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &tree[i + base]); // 제일 아래 노드에 순서대로 숫자를 저장
    }

    for (long long i = base; i > 0; i--)
    {                                            // 밑에서 2번째 줄부터 시작해서 제일 위까지
        tree[i] = tree[i * 2] + tree[i * 2 + 1]; // 자식 노드 두개를 합한 값을 현재 노드에 저장
    }

    for (long long i = 0; i < m + k; i++)
    {
        scanf("\n%lld %lld %lld", &oper, &from, &to);
        switch (oper)
        {
        case 1: // 1이면 숫자 교체
            from += base;
            int change = to - tree[from]; // 원래 있던 숫자를 빼고 새로 들어갈 숫자를 더한다.
            while (from != 0)
            {
                tree[from] += change; // 현재 노드 값 변경
                from /= 2;            // 현재 노드의 부모 노드로
            }
            break;
        case 2:           // 2이면 부분 합 구하기
            result = 0;   // 합을 0으로 초기화
            from += base; // 제일 아래 위치한
            to += base;
            while (from <= to)
            {
                if (from % 2 == 1)          // 두개의 형제 노드 중 우측 노드면
                    result += tree[from++]; // 해당 값을 더하고 이후 노드로 이동(우측으로 한칸)
                if (to % 2 == 0)            // 두개의 형제 노드 중 좌측 노드면
                    result += tree[to--];   // 해당 값을 더하고 이전 노드로 이동(좌측으로 한칸)
                from /= 2;                  // 현재 노드의 부모 노드로
                to /= 2;                    // 현재 노드의 부모 노드로
            }
            printf("%lld\n", result);
            break;
        }
    }

    free(tree); // 동적 할당 해제
    return 0;
}
