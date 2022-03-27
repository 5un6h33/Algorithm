#include <iostream>
#include <algorithm>
using namespace std;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int r, c;
int maxSum;
int map[501][501], v[501][501];
void chk();
void dfs(int y, int x, int sum, int dep)
{
    if (dep == 4)
    {
        maxSum = max(maxSum, sum);
        return;
    }
    v[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= c || ny >= r || v[ny][nx] == 1)
            continue;

        dfs(ny, nx, sum + map[ny][nx], dep + 1);
    }
    v[y][x] = 0;
}
int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> map[i][j];
    }
    maxSum = -1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dfs(i, j, map[i][j], 1);
    chk();
    cout << maxSum << '\n';
}

void chk()
{
    int m = -1, val;
    for (int i = 0; i < r - 2; i++)
    { // ㅏ
        for (int j = 0; j < c - 1; j++)
        {
            val = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
            m = m > val ? m : val;
        }
    }
    for (int i = 0; i < r - 2; i++)
    { //ㅓ
        for (int j = 1; j < c; j++)
        {
            val = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
            m = m > val ? m : val;
        }
    }
    for (int i = 0; i < r - 1; i++)
    { //ㅗ
        for (int j = 1; j < c - 1; j++)
        {
            val = map[i][j] + map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
            m = m > val ? m : val;
        }
    }
    for (int i = 0; i < r - 1; i++)
    { //ㅜ
        for (int j = 1; j < c - 1; j++)
        {
            val = map[i][j] + map[i][j - 1] + map[i][j + 1] + map[i + 1][j];
            m = m > val ? m : val;
        }
    }
    maxSum = max(maxSum, m);
}
