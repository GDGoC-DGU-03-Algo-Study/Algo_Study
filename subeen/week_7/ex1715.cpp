#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int result = 0;
	while (!pq.empty()) {
		int a, b;
		a = pq.top(); pq.pop();

		if (pq.empty()) break;

		b = pq.top(); pq.pop();
		result += a + b;
		pq.push(a + b);
	}

	cout << result << "\n";
	return 0;
}