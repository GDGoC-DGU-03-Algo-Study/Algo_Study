#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void permutation(int n, int k, vector<int> &inputList, vector<string> &numberList, int depth, vector<string> &out, vector<bool> &visited)
{
    if (depth == k)
    {
        string number = "";
        for (int i = 0; i < out.size(); i++)
        {
            number += out[i];
        }
        if (find(numberList.begin(), numberList.end(), number) == numberList.end())
        {
            numberList.push_back(number);
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            string s = to_string(inputList[i]);
            out.push_back(s);
            permutation(n, k, inputList, numberList, depth + 1, out, visited);
            visited[i] = false;
            out.pop_back();
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> inputList(n);
    vector<string> numberList;
    vector<string> out;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputList[i];
    }
    permutation(n, k, inputList, numberList, 0, out, visited);
    cout << numberList.size();
}