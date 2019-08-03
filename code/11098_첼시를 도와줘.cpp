#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, string>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		cout << v[n - 1].second << endl;
	}
}