#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n, w, L;
    cin >> n >> w >> L;
    vector<int> weightList(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weightList[i];
    }
    queue<int> bridge;
    for (int i = 0; i < w; i++)
    {
        bridge.push(0);
    }
    int time = 0;
    int currentWeightSum = 0;
    int currentIndex = 0;
    while (1)
    {
        currentWeightSum -= bridge.front();
        bridge.pop();
        if (currentIndex >= n)
        {
            if (currentWeightSum == 0)
            {
                time++;
                break;
            }
            else
            {
                while (!bridge.empty())
                {
                    currentWeightSum -= bridge.front();
                    bridge.pop();
                    time++;
                }
                time++;
                break;
            }
        }
        if (currentWeightSum + weightList[currentIndex] <= L)
        {
            bridge.push(weightList[currentIndex]);
            currentWeightSum += weightList[currentIndex];
            currentIndex++;
        }
        else
        {
            bridge.push(0);
        }
        time++;
    }
    cout << time;
}