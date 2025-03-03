#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int num;
        vector<int> v;

        for (int i = 0; i < N; i++)
        {
            cin >> num;
            v.push_back(num);
        }

        long long total = 0;
        int Max = v[v.size() - 1];

        for (int i = v.size() - 2; i >= 0; i--)
        {
            if (v[i] < Max)
            {
                total += Max - v[i];
            }
            Max = max(Max, v[i]);
        }
        cout << total << '\n';
    }

    return 0;
}