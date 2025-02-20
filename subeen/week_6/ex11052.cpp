#include <iostream>
#include <algorithm>
using namespace std;

int p[1000], r[1000];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            r[i] = max(r[i], r[i - j] + p[j]);
        }
    }

    cout << r[n] << "\n";
    return 0;
}