#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)

int n, ans;
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {0, 1, 1, -1, -1, 0};
char map[51][51];
int color[51][51];

void dfs(int x, int y, int c)
{
  color[x][y] = c;
  ans = MAX(ans, 1);
  for (int i = 0; i < 6; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
      continue;
    if (map[nx][ny] == 'X')
    {
      if (color[nx][ny] == -1)
      {
        dfs(nx, ny, 1 - c);
        ans = MAX(ans, 2);
      }
      else if (color[nx][ny] == c)
      {
        ans = 3;
        return;
      }
    }
  }
}

int main(void)
{
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf(" %c", &map[i][j]);

  memset(color, -1, sizeof(color));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (map[i][j] == 'X' && color[i][j] == -1 && ans < 3)
        dfs(i, j, 0);

  printf("%d\n", ans);

  return 0;
}
