#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> A, B;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        B.push_back(num);
    }
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    int sum1 = 0, sum2 = 0;
    ;
    for (int i = 0; i < N; i++)
    {
        sum1 += A[i] * B[i];
    }

    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++)
    {
        sum2 += A[i] * B[i];
    }
    cout << min(sum1, sum2) << endl;
}