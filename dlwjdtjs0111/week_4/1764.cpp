#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    string str;
    cin >> N >> M;
    vector<string> v1;
    string seename;
    vector<string> list;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        v1.push_back(str);
    }

    sort(v1.begin(), v1.end());
    for (int i = 0; i < M; i++)
    {
        cin >> seename;
        if (binary_search(v1.begin(), v1.end(), seename))
        {
            list.push_back(seename);
        }
    }
    sort(list.begin(), list.end());
    cout << list.size() << endl;
    for (auto a : list)
    {
        cout << a << endl;
    }
}