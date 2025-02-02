#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, W, L;
    cin >> N >> W >> L;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }

    int T = 0;
    int weight = 0;
    queue<int> bridge;
    int temp;
    for (int i = 0; i < W; i++)
    {
        bridge.push(0);
    }

    while (!q.empty())
    {
        T++;
        weight -= bridge.front();
        bridge.pop();
        if (weight + q.front() <= L)
        {
            weight += q.front();
            bridge.push(q.front());
            q.pop();
        }
        else
        {
            bridge.push(0);
        }
        if (q.empty())
        {
            while (!bridge.empty())
            {
                bridge.pop();
                T++;
            }
        }
    }

    cout << T;
    return 0;
}