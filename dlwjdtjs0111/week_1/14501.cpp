#include <iostream>
#include <algorithm>
using namespace std;

void solution(vector<pair<int, int> > &v, vector<int> &dp, int N) {
    for(int i = N-1; i >= 0; i --) {
        int nextDay = i + v[i].first;
        if(nextDay <= N) {
            dp[i] = max(dp[i+1], dp[nextDay] + v[i].second);
        } else {
            dp[i] = dp[i + 1];
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int> > v;
    for(int i = 0; i < N; i++) {
        int day, money;
        cin >> day >> money;
        v.push_back(make_pair(day, money));
    } 
    vector<int> dp(N + 1);
    fill(dp.begin(), dp.end(), 0);
    solution(v, dp, N);
    cout << dp[0];
}
