#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N, S, total = 0;
    cin >> N >> S;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }
    for (int i = 1; i < (1 << N); i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                sum += list[j];
            }
        }
        if (sum == S)
        {
            total += 1;
        }
    }
    cout << total;
}