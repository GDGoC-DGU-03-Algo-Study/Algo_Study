#include <bits/stdc++.h>
using namespace std;

long long dp[31][31];

long long combi(int m, int n)
{
    if (n == 0 || m == n)
        return 1;
    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = combi(m - 1, n - 1) + combi(m - 1, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    int T;
    cin >> T;

    int n, m;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> m;
        cout << combi(m, n) << '\n';
    }

    return 0;
}