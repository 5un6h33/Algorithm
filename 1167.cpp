#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node
{
    int index;
    int dist;
};

int n, maxDist, maxNode;
bool visited[100001];
vector<Node> graph[100001];

void dfs(int node, int dist)
{
    if (visited[node])
        return;

    if (maxDist < dist)
    {
        maxDist = dist;
        maxNode = node;
    }
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextIndex = graph[node][i].index;
        int nextDist = graph[node][i].dist;
        dfs(nextIndex, nextDist + dist);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    cin >> n;
    int from, to, dist;
    for (int i = 1; i <= n; i++)
    {
        cin >> from;
        while (true)
        {
            cin >> to;
            if (to == -1)
                break;
            cin >> dist;
            graph[from].push_back({to, dist});
            graph[to].push_back({from, dist});
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxDist = 0;

    dfs(maxNode, 0);

    cout << maxDist << '\n';

    return 0;
}
