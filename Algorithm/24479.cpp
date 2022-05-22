#include<iostream>
#include<vector>
#include<algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m, r;
int u, v;
int idx = 1;
int visited[200001];
vector<int> vec[200001];

void dfs(int cur)
{
    visited[cur] = idx++;
    for(auto &next : vec[cur])
    {
        if(visited[next] != 0)
            continue;
        dfs(next);
    }
}

int main(void)
{
    fastio;
//    freopen("input.txt", "r", stdin);
    
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++)
        sort(vec[i].begin(), vec[i].end());
    
    dfs(r);
    
    for(int i = 1; i <= n; i++)
        cout << visited[i] << '\n';
    
    return 0;
}
