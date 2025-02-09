#include <bits/stdc++.h>
using namespace std;
char arr[602][602];
int visited[602][602];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int total = 0;
int N, M;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (visited[ny][nx] == 1)
            continue;
        if (arr[ny][nx] == 'O')
            dfs(ny, nx);
        if (arr[ny][nx] == 'P')
        {
            total++;
            dfs(ny, nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int y, x;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
    }
    dfs(y, x);

    if (total == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << total;
    }

    return 0;
}