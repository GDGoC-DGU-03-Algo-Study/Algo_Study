#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> cards;
    cards.push_back(0);
    vector<int> dp(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cards.push_back(num);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            dp[i] = max(dp[i], dp[i - j] + cards[j]);
        }
    }
    cout << dp[N];
}