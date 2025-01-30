using namespace std;
#include <iostream>
int main() {
	int e, s, m;
	cin >> e >> s >> m;
	int year = 0;

	for (int i = 0; i < 10000; i++) {

		if ((e == 15) && (s == 28) && (m == 19)) {
			year = e * s * m;
			cout << year;
			return 0;
		}


		year = 15 * i + (e % 15);
		if ((year - (s % 28)) % 28 == 0) {
			if ((year - (m % 19)) % 19 == 0) {
				cout << year;
				return 0;
			}
		}

	}
}
