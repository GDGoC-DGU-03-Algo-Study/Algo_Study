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
        // ���������� �ִ� ���� ����
        r[i] = max(r[i], r[i - 1]);

        // ����� ������ ��츸 ���� ����
        // i+t[i]-1 �� ��� ���� ��¥
        if ((i + t[i] - 1) <= n) {
            r[i + t[i] - 1] = max(r[i + t[i] - 1], r[i - 1] + p[i]);
        }
    }

    //�ִ� ���� ���
    cout << r[n];

    return 0;
}