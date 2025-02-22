#include <bits/stdc++.h>
using namespace std;

int Max = 0;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    int N;
    int num1, num2;
    while (T--)
    {
        Max = 0;
        cin >> N;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++)
        {
            cin >> num1 >> num2;
            v.push_back({num1, num2});
        }
        sort(v.begin(), v.end());
        int count = 1;
        int min = v[0].second;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].second < min)
            {
                count++;
                min = v[i].second;
            }
        }
        cout << count << '\n';
    }

    return 0;
}