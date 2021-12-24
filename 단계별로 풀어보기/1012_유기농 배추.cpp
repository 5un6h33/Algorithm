#include<iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int T, M, N, K, x, y, cnt;
int map[50][50];
int v[50][50];

void reset()
{
    for(int i = 0; i < 50; i++)
        for(int j = 0; j < 50; j++)
            map[i][j] = v[i][j] = 0;
    cnt = 0;
}

void dfs(int m, int n)
{
    v[m][n] = 1;
    for(int k = 0; k < 4; k++)
    {
        int nx = m + dx[k];
        int ny = n + dy[k];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N)
            if(map[nx][ny] == 1 && v[nx][ny] == 0)
                dfs(nx, ny);
    }
}

int main(void)
{
    cin >> T;
    
    while(T--)
    {
        cin >> M >> N >> K;
        reset();

        for(int i = 0; i < K; i++)
        {
            cin >> x >> y;
            map[x][y] = 1;
        }

        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(map[i][j] == 1 && v[i][j] == 0)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}