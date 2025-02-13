#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int input[101][101];
int map[101][101];
bool visited[101][101];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
vector<int> v;

void DFS(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (map[ny][nx] && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}

void reset(int &count)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    count = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
    int maxHeight = -1;
    int count = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input[i][j];
            if (input[i][j] > maxHeight)
            {
                maxHeight = input[i][j];
            }
        }
    }

    for (int h = 1; h <= maxHeight; h++)
    {

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (input[i][j] < h)
                {
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] && !visited[i][j])
                {
                    DFS(i, j);
                    count++;
                }
            }
        }
        v.push_back(count);
        reset(count);
    }

    sort(v.begin(), v.end());
    cout << v[v.size() - 1];
}
