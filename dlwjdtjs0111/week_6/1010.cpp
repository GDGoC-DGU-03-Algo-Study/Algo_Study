#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    int T, N, M;
    cin >> T;
    vector<pair<int, int>> bridge;
    vector<ll> answers;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        bridge.push_back(make_pair(N, M));
    }
    for (int i = 0; i < T; i++)
    {
        ll num1 = 1;
        ll num2 = 1;
        ll answer = 1;
        ll currentN = bridge[i].first;
        ll currentM = bridge[i].second;

        if (currentN == currentM)
        {
            answers.push_back(answer);
            continue;
        }
        if (currentN > currentM - currentN)
        {
            currentN = currentM - currentN;
        }
        int num = 1;

        for (ll j = currentN; j >= 1; --j)
        {
            num1 = num1 * j;
        }
        while (num <= currentN)
        {
            num2 = num2 * currentM;
            currentM--;
            num++;
        }
        answer = num2 / num1;
        answers.push_back(answer);
    }
    for (int i = 0; i < T; i++)
    {
        cout << answers[i] << endl;
    }
}