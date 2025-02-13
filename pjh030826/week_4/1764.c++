#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_set<string> US;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        US.insert(s);
    }
    vector<string> v;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (US.find(s) != US.end())
        {
            v.push_back(s);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (string s : v)
        cout << s << '\n';

    return 0;
}