// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N, K;
    vector<pair<ll, ll>> list;
    list.push_back(make_pair(0, 0));
    cin >> N >> K;
    for (ll i = 0; i < N; i++)
    {
        ll W, V;
        cin >> W >> V;
        list.push_back(make_pair(W, V));
    }
    vector<vector<ll>> dp(K + 1, vector<ll>(N + 1, 0));
    for (ll kg = 1; kg <= K; kg++)
    {
        for (ll item = 1; item <= N; item++)
        {
            if (kg < list[item].first)
            {
                dp[kg][item] = dp[kg][item - 1];
                continue;
            }
            dp[kg][item] = max(dp[kg - list[item].first][item - 1] + list[item].second, dp[kg][item - 1]);
        }
    }
    cout << dp[K][N] << endl;
}