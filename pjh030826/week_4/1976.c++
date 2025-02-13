#include <bits/stdc++.h>
using namespace std;
vector<int> adj[202];
int visited[202];

void bfs(int city)
{
    queue<int> q;
    q.push(city);
    visited[city] = 1;
    while (q.size())
    {
        int temp = q.front();
        q.pop();
        for (int i : adj[temp])
        {
            if (visited[i])
                continue;
            visited[i] = 1;
            q.push(i);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int num;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> num;
            if (num)
                adj[i].push_back(j);
        }
    }

    int city;
    vector<int> course;

    for (int i = 0; i < M; i++)
    {
        cin >> city;
        course.push_back(city);
    }

    bfs(course[0]);

    for (int i : course)
    {
        if (visited[i])
        {
            continue;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}