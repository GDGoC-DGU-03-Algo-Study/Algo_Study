
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, k;
vector<string>num;
bool check[10];
set<int>s;

void solve(int index, string str) {
    if (index == k) {
        int a = stoi(str);
        s.insert(a);
        return;
    }

    else {
        for (int i = 0; i < n; i++) {
            if (!check[i]) {
                check[i] = true;
                solve(index + 1, str + num[i]);
                check[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        num.push_back(str);
    }

    solve(0, "");
    cout << s.size();
    return 0;
}
