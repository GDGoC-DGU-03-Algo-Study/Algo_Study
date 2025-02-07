#include <iostream>
#include <vector>

using namespace std;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int N;
int M;

void dfs(vector<vector<char>> &campus, pair<int, int> start, int &count, vector<vector<bool>> &visited)
{
    int x = start.first;
    int y = start.second;
    visited[x][y] = true;

    if (campus[x][y] == 'P')
    {
        count++;
        campus[x][y] = '0';
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= N || nx < 0 || ny >= M || ny < 0)
        {
            continue;
        }
        if (visited[nx][ny])
        {
            continue;
        }
        if (campus[nx][ny] == 'X')
        {
            continue;
        }
        dfs(campus, make_pair(nx, ny), count, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int count = 0;
    vector<vector<char>> campus(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    pair<int, int> currentIndex;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            cin >> campus[i][j];
            visited[i][j] = false;
            if (campus[i][j] == 'I')
            {
                currentIndex = make_pair(i, j);
            }
        }
    }
    dfs(campus, currentIndex, count, visited);
    if (count == 0)
    {
        cout << "TT" << endl;
    }
    else
    {
        cout << count << endl;
    }
}