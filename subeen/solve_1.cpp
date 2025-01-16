#include <iostream>
using namespace std;

int queens[15];
int total = 0;

bool check(int row, int col) { //퀸을 놓을 수 있는지 체크
    for (int i = 0; i < row; i++) { // 0부터 row까지 i행
        if (queens[i] == col) return false; // 같은 열에 다른 queen이 있는지
        else if (i - queens[i] == row - col)  return false; //대각선
        else if (i + queens[i] == row + col) return false;
    }
    return true;
}

void search(int selected, int n) {
    int i = 0;
    if (selected == n) { //모든 행에 퀸 배치한 경우 종료
        total++;
        return;
    }
    else {
        while (i < n) {    // 퀸을 배치할 수 있는지 탐색
            if (check(selected, i)) { //체크해서 놓을 수 있으면
                queens[selected] = i; // 퀸 놓고
                search(selected + 1, n); // 다음 행 탐색
            }
            i++; // 놓을 수 없으면 다음 열 탐색
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