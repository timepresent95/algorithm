#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int mr[4] = {0, 0, 1, -1};
int mc[4] = {1, -1, 0, 0};

// 0: 모든 빙산이 녹아버림, else: 현재 빙산의 개수
int countIceberg(vector<vector<int>> &map)
{
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, int>> taskQueue;
  int ret = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (map[i][j] == 0 || visited[i][j])
      {
        continue;
      }
      taskQueue.push({i, j});
      visited[i][j] = true;
      ret++;
      while (!taskQueue.empty())
      {
        int r = taskQueue.front().first;
        int c = taskQueue.front().second;
        taskQueue.pop();
        for (int k = 0; k < 4; k++)
        {
          int nextR = r + mr[k];
          int nextC = c + mc[k];
          if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m ||
              visited[nextR][nextC] || map[nextR][nextC] == 0)
          {
            continue;
          }
          visited[nextR][nextC] = true;
          taskQueue.push({nextR, nextC});
        }
      }
    }
  }
  return ret;
}

void meltIceberg(vector<vector<int>> &map)
{
  vector<vector<int>> meltingScale(n, vector<int>(m, 0));

  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < m; c++)
    {
      if (map[r][c] == 0)
      {
        continue;
      }
      for (int k = 0; k < 4; k++)
      {
        int nextR = r + mr[k];
        int nextC = c + mc[k];
        if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m || map[nextR][nextC] != 0)
        {
          continue;
        }
        meltingScale[r][c]++;
      }
    }
  }
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < m; c++)
    {
      map[r][c] = max(map[r][c] - meltingScale[r][c], 0);
    }
  }
}

void printMap(vector<vector<int>> &map)
{
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < m; c++)
    {
      cout << map[r][c] << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<vector<int>> map(n, vector<int>(m));

  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < m; c++)
    {
      cin >> map[r][c];
    }
  }
  int elapsedYears = 0;
  while (true)
  {
    elapsedYears++;
    meltIceberg(map);
    int numberIcebergs = countIceberg(map);
    if (numberIcebergs == 0)
    {
      cout << 0;
      break;
    }
    else if (numberIcebergs != 1)
    {
      cout << elapsedYears;
      break;
    }
  }

  return 0;
}