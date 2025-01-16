#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t[16], p[16], r[16] = { 0 };

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        // 이전까지의 최대 수익 갱신
        r[i] = max(r[i], r[i - 1]);

        // 상담이 가능한 경우만 수익 갱신
        // i+t[i]-1 은 상담 후의 날짜
        if ((i + t[i] - 1) <= n) {
            r[i + t[i] - 1] = max(r[i + t[i] - 1], r[i - 1] + p[i]);
        }
    }

    //최대 수익 출력
    cout << r[n];

    return 0;
}