#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main()
{
    int N, ans = 0;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    while (!pq.empty())
    {
        int sum = 0;
        sum += pq.top();
        pq.pop();
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
            if (!pq.empty())
                pq.push(sum);
        }
        ans += sum;
    }

    cout << ans << endl;
    return 0;
}