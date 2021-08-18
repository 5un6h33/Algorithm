// #include<iostream>
// #include<queue>

// using namespace std;

// #define X first
// #define Y second

// string board[100];
// int dist[100][100];
// int n, m;
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

// int main(void)
// {
//     cin >> n >> m;

//     for(int i = 0; i < n; i++)
//         cin >> board[i];
//     for(int i = 0; i < n; i++) 
        // fill(dist[n], dist[n] + m, -1);
//     queue<pair<int, int> > Q;
//     Q.push({ 0, 0 });
//     dist[0][0] = 0;
//     while(!Q.empty())
//     {
//         auto cur = Q.front(); Q.pop();
//         for(int dir = 0; dir < 4; dir++)
//         {
//             int nx = cur.X + dx[dir];
//             int ny = cur.Y + dy[dir];
//             if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//             if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
//             dist[nx][ny] = dist[cur.X][cur.Y] + 1;
//             Q.push({ nx, ny });
//         }
//     }
//     cout << dist[n - 1][m - 1] + 1;

//     return 0;
// }

// recursion

// #include<iostream>
// #include<queue>

// using namespace std;

// #define X first
// #define Y second

// char map[100][100];
// int check[100][100];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// int n, m;

// void bfs(int x, int y);

// int main(void)
// {
//     cin >> n >> m;
//     for(int i = 0; i < n; i++)
//         cin >> map[i];
//     bfs(0, 0);

//     cout << check[n - 1][m - 1] << endl;

//     return 0;
// }

// void bfs(int x, int y)
// {
//     queue<pair<int, int> > Q;
//     Q.push({ x, y });
//     check[x][y] = 1;
//     while(!Q.empty())
//     {
//         x=Q.front().X;
// 		y=Q.front().Y;
//         for(int dir = 0; dir < 4; dir++)
//         {
//             int nx = x + dir;
//             int ny = y + dir;
//             if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//             if(check[nx][ny] || map[nx][ny] != '1') continue;
//             Q.push( { nx, ny } );
//             check[nx][ny] = check[x][y] + 1;
//         }
//     }
// }


#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define X first
#define Y second

string borad[100];
int dist[100][100];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{   
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> borad[i];

    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    
    queue<pair <int, int> > Q;
    Q.push( { 0, 0 } );
    dist[0][0] = 0;
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] >= 0 || borad[nx][ny] != 1)  continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push( { nx, ny } );
        }
    }

    cout << dist[n - 1][m - 1] + 1;

    return 0;
}