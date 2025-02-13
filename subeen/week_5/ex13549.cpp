#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001];

void bfs(int n, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	//greater : ù��° �� ���� ������ ����
	//�ҿ�ð� ���� ��ġ �켱 Ž��
	pq.push({ 0,n }); // {�ҿ�ð�, ������ġ}
	visited[n] = 1;

	while (!pq.empty()) {
		int cnt = pq.top().first; //�ɸ� �ð�
		int num = pq.top().second; //���� ��ġ
		pq.pop();

		if (num == k) { 
			cout << cnt; //�ð� ���
			return;
		}

		if (num * 2 < 100001 && !visited[num * 2]) { //�����̵�
			visited[num * 2] = 1;
			pq.push({ cnt, num * 2 });
		}
		if (num - 1 >= 0 && !visited[num - 1]) { //�ڷ� �� ĭ
			visited[num - 1] = 1;
			pq.push({ cnt + 1, num - 1 });
		}
		if (num + 1 < 100001 && !visited[num + 1]) { //������ �� ĭ
			visited[num + 1] = 1;
			pq.push({ cnt + 1, num + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	cin >> n >> k;
	bfs(n, k);
}