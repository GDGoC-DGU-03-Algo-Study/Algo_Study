#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string>v(n); 
	vector<string>result;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	string s;
	for (int i = 0; i < m; i++) {
		cin >> s; 
		if (binary_search(v.begin(), v.end(), s)) {
			result.push_back(s);
		}

	}
	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (string s1 : result) cout << s1 << "\n";
}