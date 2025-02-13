#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> campus;
vector<vector<bool>> visited;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int count = 0;

    while (!q.empty()) {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];

            // 범위를 벗어나지 않고 방문하지 않았고 벽이 아닌 경우
            if ((x2 >= 0) && (x2 < n) && (y2 >= 0) && (y2 < m) && (!visited[x2][y2]) && (campus[x2][y2] != 'X')){
                visited[x2][y2] = true;
                q.push({ x2, y2 });

                if (campus[x2][y2] == 'P') {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    campus.assign(n, vector<char>(m)); 
    visited.assign(n, vector<bool>(m, false)); 
    int x, y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') { //위치 정보 저장
                x = i;
                y = j;
            }
        }
    }

    int result = bfs(x, y);

    if (result > 0) {
        cout << result;
    }
    else {
        cout << "TT";
    }
    return 0;
}
