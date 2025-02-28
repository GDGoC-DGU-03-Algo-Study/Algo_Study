#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> p(M, -1);
    vector<int> n(M, -1);
    for (int i = 0; i < M; i++)
    {
        cin >> p[i] >> n[i];
    }

    sort(p.begin(), p.end());
    sort(n.begin(), n.end());

    int total = 0;
    while (N > 0)
    {
        if (N >= 6)
        {
            if (p[0] < n[0] * 6)
            {
                total += p[0];
                N -= 6;
            }
            else
            {
                total += N * n[0];
                N -= N;
            }
        }
        else
        {
            if (N * n[0] < p[0])
            {
                total += N * n[0];
                N -= N;
            }
            else
            {
                total += p[0];
                N -= 6;
            }
        }
        // cout << N << " " << total << '\n';
    }

    cout << total;
    return 0;
}