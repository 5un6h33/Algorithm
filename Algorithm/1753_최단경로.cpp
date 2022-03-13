#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int v, e, k;
int d[200001];
vector<pair<int, int>> vec[20001];

void dijkstra(int start)
{
  d[start] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});
  while(!pq.empty())
  {
    int distance = -pq.top().first;
    int current = pq.top().second;
    pq.pop();
    if(d[current] < distance) continue;
    for(int i = 0; i < vec[current].size(); i++)
    {
      int next = vec[current][i].first;
      int nextDistance = distance + vec[current][i].second;
      if(nextDistance < d[next])
      {
        d[next] = nextDistance;
        pq.push({-nextDistance, next});
      }
    }
  }
}

int main(void)
{
  int a, b, c;  
  scanf("%d %d %d", &v, &e, &k);
  while(e--)
  {
    scanf("%d %d %d", &a, &b, &c);
    vec[a].push_back({b, c});
  }

  for(int i = 1; i <= v; i++)
    d[i] = INF;
  
  dijkstra(k);

  for(int i = 1; i <= v; i++)
  {
    if(d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", d[i]);
  }
  
  return 0;
}
