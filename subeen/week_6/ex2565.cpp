#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
    int n, dp[101];
    cin >> n;
    int a, b;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end());

    int result = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (dp[j] + 1 > dp[i] && v[i][1] > v[j][1]) {
                dp[i] = dp[j] + 1;
            }
        }

        result = max(result, dp[i]);
    }

    cout << n - result;
}