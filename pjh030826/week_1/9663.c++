#include <bits/stdc++.h>
using namespace std;
int arr[15];
int N;
int cnt = 0;

void cal(int n)
{
    if (n == N)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        arr[n] = i;
        bool b = true;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[n] || abs(arr[n] - arr[j]) == n - j)
            {
                b = false;
                break;
            }
        }
        if (b)
            cal(n + 1);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cal(0);
    cout << cnt;
    return 0;
}