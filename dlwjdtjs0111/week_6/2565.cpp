#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> lines;
    vector<int> LCS;
    int dp[101];
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        lines.push_back(make_pair(A, B));
    }
    sort(lines.begin(), lines.end());
    for (int i = 0; i < N; i++)
    {
        LCS.push_back(lines[i].second);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (dp[j] + 1 > dp[i] && LCS[i] > LCS[j])
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << N - ans;
}