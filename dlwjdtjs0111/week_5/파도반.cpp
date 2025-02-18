#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<long long> P(101);
    vector<int> input(T);
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;

    for (int i = 6; i <= 100; i++)
    {
        P[i] = P[i - 1] + P[i - 5];
    }
    for (int i = 0; i < T; i++)
    {
        cin >> input[i];
    }
    for (int i = 0; i < T; i++)
    {
        cout << P[input[i]] << endl;
    }
}