#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin >> T;
    vector<ll> testCase;
    vector<ll> calculate(12, 0);
    for (ll i = 0; i < T; i++)
    {
        ll num;
        cin >> num;
        testCase.push_back(num);
    }
    calculate[1] = 1;
    calculate[2] = 2;
    calculate[3] = 4;
    for (ll i = 4; i < 12; i++)
    {
        calculate[i] = calculate[i - 1] + calculate[i - 2] + calculate[i - 3];
    }
    for (ll i = 0; i < T; i++)
    {
        cout << calculate[testCase[i]] << endl;
    }
}