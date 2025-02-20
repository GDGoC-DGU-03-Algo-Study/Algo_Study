#include <iostream>
using namespace std;
int main() {
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		//mCn
		int result = 1;
		int k = 1;
		for (int j = m; j > m - n; j--) {
			result *= j;
			result /= k;
			k++;
		}
		cout << result << "\n";
	}
	return 0;
}