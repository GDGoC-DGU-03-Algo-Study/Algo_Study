#include <bits/stdc++.h>
using namespace std;

int arr[1002];
vector<int> v;

int cal(int N)
{
    if (N == 1)
        arr[N] = v[N - 1];
    int Max = v[N - 1];

    for (int i = 1; i <= N / 2; i++)
    {

        if (arr[N - i] == -1)
            arr[N - i] = cal(N - i);
        if (arr[i] == -1)
            arr[i] = cal(i);
        // cout << arr[N - i] << " " << arr[i] << '\n';

        Max = max(Max, arr[N - i] + arr[i]);
    }
    return Max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    memset(arr, -1, sizeof(arr));

    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    cout << cal(N);

    return 0;
}