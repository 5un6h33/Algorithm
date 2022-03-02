#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define RED 1
#define BLUE 2

using namespace std;

int k, v, e, color;
int visited[20001] = {0, };
vector<int> adj[20001];

void bfs(int start)
{
  queue<int> q;
  int color = RED;
  visited[start] = RED;
  q.push(start);
  while(!q.empty())
  {
    int x = q.front();
    q.pop();

    if(visited[x] == RED)
      color = BLUE;
    else
      color = RED;

    for(int i = 0; i < adj[x].size(); i++)
    {
      int nx = adj[x][i];
      if(!visited[nx])
      {
        visited[nx] = color;
        q.push(nx);
      }
    }
  }
}

int check()
{
  for(int i = 1; i <= v; i++)
  {
    for(int j = 0; j < adj[i].size(); j++)
    {
        int nx = adj[i][j];
        if(visited[i] == visited[nx])
          return 0;
    }
  }
  return 1;
}

int main(void)
{
  // freopen("input.txt", "r", stdin);
  cin >> k;
  while(k--)
  {
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for(int i = 1; i <= v; i++)
      if(!visited[i])
        bfs(i);

    if(check())
      printf("YES\n");
    else
      printf("NO\n");
    
    for(int i = 0; i <= v; i++)
      adj[i].clear();
    memset(visited, 0, sizeof(visited));
  }

  return 0;
}
