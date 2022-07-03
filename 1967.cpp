#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node
{
    int index;
    int dist;
};

int N, maxNode, maxDist;
vector<Node> graph[10001];
bool visited[10001];

void dfs(int cur, int dist)
{
    if (visited[cur])
        return;
    if (maxDist < dist)
    {
        maxDist = dist;
        maxNode = cur;
    }

    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int ncur = graph[cur][i].index;
        int ndist = graph[cur][i].dist + dist;
        dfs(ncur, ndist);
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int s, e, v;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> s >> e >> v;
        graph[s].push_back({e, v});
        graph[e].push_back({s, v});
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(maxNode, 0);
    cout << maxDist;
    return 0;
}
