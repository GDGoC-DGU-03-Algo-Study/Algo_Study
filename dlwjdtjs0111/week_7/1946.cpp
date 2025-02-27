#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int T, N, sum = 0;
    vector<int> answer;
    cin >> T;
    vector<pair<int, int>> test;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int interview, grade;
            cin >> grade >> interview;
            test.push_back(make_pair(grade, interview));
        }
        sort(test.begin(), test.end());
        int tmp = 0;
        sum = 1;
        for (int k = 1; k < N; k++)
        {
            if (test[tmp].second > test[k].second)
            {
                sum++;
                tmp = k;
            }
        }
        test.clear();
        answer.push_back(sum);
    }

    for (int i = 0; i < T; i++)
    {
        cout << answer[i] << endl;
    }
}