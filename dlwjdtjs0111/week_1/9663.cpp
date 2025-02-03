#include <iostream>
#include <vector>
using namespace std;

bool confirm(int row, vector<int> &queenColumn) {
    for(int i = 0; i < row; i++) {
        if((queenColumn[row] == queenColumn[i] || (abs(queenColumn[row] - queenColumn[i]) == abs(row - i)))) {
            return false;
        }
    }
    return true;
}

void dfs(int &cnt, int row, int N, vector<int> &queenColumn) {
    if(row == N) {
        cnt+=1;
        return;
    }
    for(int col = 0; col < N; col ++) {
        queenColumn[row] = col;
        if(confirm(row, queenColumn)){
            dfs(cnt, row+1, N, queenColumn);
        } 
    }
}

int main() {
    int N, row = 0, cnt = 0;
    cin >> N;
    vector<int> queenColumn(N);
    dfs(cnt, row, N, queenColumn);
    cout << cnt;
}


//하나의 열, 하나의 행에 하나의 퀸만 배치 가능
