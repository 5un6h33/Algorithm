#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
string board[25];
bool v[25][25] = {false, };
int n, cnt;
vector <int> ans;

void dfs(int i, int j)
{
    v[i][j] = true;
    cnt++;

    for(int k = 0; k < 4; k++)
    {        
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 && x < n && y >= 0 && y < n)
            if(board[x][y] == '1' && v[x][y] == false)
                dfs(x, y);
    }
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '1' && v[i][j] == false)
            {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    sort(begin(ans), end(ans));

    cout << ans.size() << endl;
    for(auto elem: ans)
        cout << elem << endl;

    return 0;
}