#include <iostream>
using namespace std;

int queens[15];
int total = 0;

bool check(int row, int col) { //���� ���� �� �ִ��� üũ
    for (int i = 0; i < row; i++) { // 0���� row���� i��
        if (queens[i] == col) return false; // ���� ���� �ٸ� queen�� �ִ���
        else if (i - queens[i] == row - col)  return false; //�밢��
        else if (i + queens[i] == row + col) return false;
    }
    return true;
}

void search(int selected, int n) {
    int i = 0;
    if (selected == n) { //��� �࿡ �� ��ġ�� ��� ����
        total++;
        return;
    }
    else {
        while (i < n) {    // ���� ��ġ�� �� �ִ��� Ž��
            if (check(selected, i)) { //üũ�ؼ� ���� �� ������
                queens[selected] = i; // �� ����
                search(selected + 1, n); // ���� �� Ž��
            }
            i++; // ���� �� ������ ���� �� Ž��
        }
    }
}

int main() {
    int n;
    cin >> n;
    search(0, n);
    cout << total;
    return 0;
}