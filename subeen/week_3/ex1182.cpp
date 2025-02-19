
#include <iostream>
using namespace std;

int n, s;
int a[20];
int total=0;

void solve(int i, int value) {
	if (i == n) return;
	if ((value + a[i]) == s) total++;

	solve(i + 1, value);
	solve(i+1, value + a[i]);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve(0, 0);

	cout << total;
	return 0;
}