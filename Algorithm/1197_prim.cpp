#include<iostream>
#include<queue>
#include<vector>
#define P pair<int, int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int visited[10001];
vector<P> edge[10001];

long long prim()
{
    long long ans = 0;
    priority_queue<P, vector<P> , greater<P>>pq; // first는 가중치 second 는 정점 minheap
    pq.push(P(0, 1)); //1번 정점부터 시작       // 가중치가 가장작은것이 top으로 가게된다!
    
    while(!pq.empty()) {
        P cur = pq.top();
        pq.pop();
        
        if(visited[cur.second]) //방문 정점 표시
            continue;
        visited[cur.second] = 1;
        
        ans += cur.first;
        
        for (int i = 0; i < edge[cur.second].size(); i++) { //현재 정점에서 이동 할 수 있는 방문하지 않은 정점 푸쉬
            if (!visited[edge[cur.second][i].second]) {
                pq.push(edge[cur.second][i]);
            }
        }
    }
     return ans;
}

int main() {
    fastio;
    freopen("input.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    
    for(int i = 0; i < E; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge[A].push_back(P(C, B));
        edge[B].push_back(P(C, A));
    }
    
    long long result = prim();
    cout<< result;
    return 0;
}
