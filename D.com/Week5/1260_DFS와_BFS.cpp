#include<iostream>
#include<queue>

using namespace std;

#define MAX 1001

int n, m, v;
int map[MAX][MAX];
bool visited[MAX] = {0, };
queue<int> q;

void reset()
{
    for(int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
}

void dfs(int v)
{
    visited[v] = true;
    cout << v << " ";

    for(int i = 1; i <= n; i++)
    {
        if(map[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int v)
{
    q.push(v);
    visited[v] = true;
    cout << v << ' ';

    while(!q.empty())
    {
        v = q.front(); q.pop();

        for(int w = 1; w <= n; w++)
        {
            if(map[v][w] == 1 && visited[w] == 0)
            {
                q.push(w);
                visited[w] = true;
                cout << w << ' ';
            }
        }

    }
}

int main(void)
{
    cin >> n >> m >> v;    

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    reset();
    dfs(v);

    cout << '\n';

    reset();
    bfs(v);

    return 0;
}