#include<iostream>
#include<string>
#include<vector>
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M, ans;
string s;
map<string, bool> m;

int main() {
    fastio;
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        cin >> s;
        m[s] = true;
    }
    
    for(int i = 0; i < M; i++)
    {
        cin >> s;
        if(m[s]) ans++;
    }
    
    cout << ans << '\n';
    
    return 0;
}
