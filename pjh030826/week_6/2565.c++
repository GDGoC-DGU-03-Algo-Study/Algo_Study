#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> wires(N);

    for (int i = 0; i < N; i++)
    {
        cin >> wires[i].first >> wires[i].second;
    }

    sort(wires.begin(), wires.end());

    vector<int> length(N, 1);
    int max_length = 1;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (wires[j].second < wires[i].second)
            {
                length[i] = max(length[i], length[j] + 1);
            }
        }
        max_length = max(max_length, length[i]);
    }
    cout << (N - max_length);
    return 0;
}
