#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int totalCost = 0;

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }

    cout << totalCost << endl;
    return 0;
}
