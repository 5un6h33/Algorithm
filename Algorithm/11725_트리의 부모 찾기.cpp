#include <cstdio>
#include <vector>
using namespace std;

int n, a, b;
vector<int> v[100001];
int visited[100001] = {1};

void dfs(int x)
{
  for(int i = 0; i < v[x].size(); i++)
  {
    int nx = v[x][i];
    if(visited[nx] == 0)
    {
      visited[nx] = x;
      dfs(nx);
    }
  }
  return;  
}

int main(void)
{
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(1);

  for(int i = 2; i <= n; i++)
    printf("%d\n", visited[i]);
  
  return 0;
}
