#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> a;
    vector<int> b;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int Sum = 0;
    for (int i = 0; i < N; i++)
    {
        Sum += a[i] * b[i];
    }

    cout << Sum;
    return 0;
}