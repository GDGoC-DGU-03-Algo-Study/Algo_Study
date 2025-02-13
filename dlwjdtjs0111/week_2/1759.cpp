#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<char> moem;

void calculate(int C, int L, int jaemCount, int moemCount, vector<char> &list, string &select, vector<string> &answer, int startIndex)
{
    if (select.length() == L)
    {
        if (moemCount >= 1 && jaemCount >= 2)
        {
            answer.push_back(select);
        }
        // jaemCount = 0;
        // moemCount = 0;
        return;
    }

    for (int i = startIndex; i < C; i++)
    {
        if (find(moem.begin(), moem.end(), list[i]) == moem.end())
        {
            select.push_back(list[i]);
            calculate(C, L, jaemCount + 1, moemCount, list, select, answer, i + 1);
            select.pop_back();
        }
        else
        {
            select.push_back(list[i]);
            calculate(C, L, jaemCount, moemCount + 1, list, select, answer, i + 1);
            select.pop_back();
        }
    }
}
int main()
{
    int L, C;
    cin >> L >> C;
    vector<char> list(C);
    string select = "";
    vector<string> answer;
    moem = {'a', 'e', 'i', 'o', 'u'};
    int moemCount = 0, jaemCount = 0;
    for (int i = 0; i < C; i++)
    {
        cin >> list[i];
    }
    sort(list.begin(), list.end());

    calculate(C, L, jaemCount, moemCount, list, select, answer, 0);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}