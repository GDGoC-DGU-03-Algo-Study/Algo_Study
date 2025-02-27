#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int arr[20];
pair<int, int> num[100000];

int main() {

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> num[j].first >> num[j].second;
		}

		sort(num, num + n);

		int max= num[0].second;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (num[i].second <= max) {
				cnt++;
				max = num[i].second;
			}
		}

		arr[i] = cnt;

	}

	for (int i = 0; i < t; i++) {
		cout << arr[i] << "\n";
	}


	return 0;
}