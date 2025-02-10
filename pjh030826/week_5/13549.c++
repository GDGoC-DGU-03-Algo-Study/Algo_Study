#include <bits/stdc++.h>
using namespace std;

int ZeroOneBFS(int N, int K)
{
    vector<int> visited(100001, -1);
    deque<int> dq;
    dq.push_front(N);
    visited[N] = 0;

    while (dq.size())
    {
        int current = dq.front();
        dq.pop_front();

        if (current == K)
        {
            return visited[current];
        }

        int next = 2 * current;
        if (next <= 100000 && visited[next] == -1)
        {
            dq.push_front(next);
            visited[next] = visited[current];
        }

        for (int i : {current - 1, current + 1})
        {
            if (i >= 0 && i < 100000 && visited[i] == -1)
            {
                dq.push_back(i);
                visited[i] = visited[current] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    cout << ZeroOneBFS(N, K) << '\n';
    return 0;
}