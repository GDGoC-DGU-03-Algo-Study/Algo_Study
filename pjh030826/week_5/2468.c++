#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int visited[102][102];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int maxValue = 1;
int value = 0;
int N;

void bfs(int n, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    while (q.size())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            if (arr[ny][nx] > n)
            {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
    return;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (arr[j][k] > i && visited[j][k] == 0)
                {
                    value++;
                    bfs(i, j, k);
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        maxValue = max(maxValue, value);
        value = 0;
    }

    cout << maxValue;
    return 0;
}