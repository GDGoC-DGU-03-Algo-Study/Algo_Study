#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    // for(int i : v) cout << i << " ";
    // cout << '\n';

    int sum = 1;
    int index = 0;
    while (sum >= v[index] && index < N)
    {
        sum += v[index];
        index++;
        // cout << sum << '\n';
    }

    cout << sum;

    return 0;
}