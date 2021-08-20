#include<iostream>
#include<queue>

using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) 
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int count = 0, max = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vis[i][j] || board[i][j] == 0) continue;
            vis[i][j] = 1;
            queue<pair<int, int> > Q;
            Q.push(pair<int, int> ( i, j ));
            int area = 0;
            while(!Q.empty())
            {
                area++;
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++)        
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny >= n || ny < 0 || ny >= m)  continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;

                    vis[nx][ny] = 1;
                    Q.push(pair<int, int> ( nx, ny ));
                }
            }
            count++;
            if(area > max)  max = area;
        }
    }

    cout << count << '\n';
    cout << max;

    return 0;
}