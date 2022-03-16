#include <stdio.h>
#define INF 987654321
#define MIN(a, b) (a < b ? a : b)

typedef struct _POS
{
  int x, y;
} POS;

int n, m, idx, res = INF;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char map[21][21];
POS start[2];

int check(POS p)
{
  if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m)
    return 1;
  return 0;
}

void dfs(int depth, POS a, POS b)
{
  if (res < depth)
    return;

  if (depth > 10)
  {
    res = MIN(res, depth);
    return;
  }

  if (check(a) && check(b))
    return;
  else if (check(a) || check(b))
  {
    res = MIN(res, depth);
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    POS na = {a.x + dx[i], a.y + dy[i]};
    POS nb = {b.x + dx[i], b.y + dy[i]};
    if (map[na.x][na.y] == '#')
      na = a;
    if (map[nb.x][nb.y] == '#')
      nb = b;
    dfs(depth + 1, na, nb);
  }
}

int main(void)
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%1s", &map[i][j]);
      if (map[i][j] == 'o')
      {
        start[idx].x = i;
        start[idx].y = j;
        idx++;
      }
    }
  }

  dfs(0, start[0], start[1]);

  if (res > 10)
    res = -1;
  printf("%d\n", res);

  return 0;
}
