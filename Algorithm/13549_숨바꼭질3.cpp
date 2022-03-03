#include<cstdio>
#include<queue>
#define MAX 100001
using namespace std;

int dx[] = {2, -1, 1};
int visited[MAX];
int dp[MAX];

void bfs(int start, int end)
{
  queue<int> q;
  q.push(start);
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    if(x == end)
    {
      printf("%d\n", dp[end]);
      break;
    }

    for(int i = 0; i < 3; i++)
    {
      int nx, time;
      if(i == 0)
      {
        nx = x * 2;
        time = 0;
      }
      else
      {
        nx = x + dx[i];
        time = 1;
      }

      if(nx < 0 || nx >= MAX)  continue;
      if(visited[nx] && dp[nx] <= dp[x] + time)  continue;
      q.push(nx);
      visited[nx] = 1;
      dp[nx] = dp[x] + time;
    }
  }
}

int main(void)
{
  int n, k;
  scanf("%d %d", &n, &k);
  bfs(n, k);
  return 0;
}
