#include<iostream>
#include<algorithm>
#include<vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int V, E, res;
int parent[10001];
vector<pair<int, pair<int, int>>> v;

int getParent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if(x < y) parent[y] = x;
    else parent[y] = x;
}
bool find(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x == y)return true;
    else return false;
}
int main() {
    fastio;
    freopen("input.txt", "r", stdin);
    
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({ cost,{from, to} });
    }
    sort(v.begin(), v.end());
    
    for (int i = 1; i <= V; i++) parent[i] = i;
    for (int i = 0; i < v.size(); i++) {
        if (!find(v[i].second.first, v[i].second.second)) {
            unionParent(v[i].second.first, v[i].second.second);
            res += v[i].first;
        }
    }
    cout << res << '\n';
}
