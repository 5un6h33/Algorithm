#include<stdio.h>

int r, c, flag;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char map[501][501];

int main(void)
{
  scanf("%d %d", &r, &c);
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      scanf("%1s", &map[i][j]);

  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      if(map[i][j] == 'S')
      {
        for(int k = 0; k < 4; k++)
        {
          int nx = i + dx[k];
          int ny = j + dy[k];

          if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
          if(map[nx][ny] == 'W')
            flag = 1;
        }
      }
    }
  }
  
  if(flag)
  {
    printf("0\n");
  }
  else
  {
    printf("1\n");
    for(int i = 0; i < r; i++)
    {
      for(int j = 0; j < c; j++)
      {
        if(map[i][j] == 'W')
        {
          for(int k = 0; k < 4; k++)
          {
            int nx = i + dx[k];
            int ny = j + dy[k];
  
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(map[nx][ny] == '.')
              map[nx][ny] = 'D'; 
          }
        }
      } 
    }
    for(int i = 0; i < r; i++)
    {
      for(int j = 0; j < c; j++)
        printf("%c", map[i][j]);
      printf("\n");
    }
  }
  
  return 0;
}
