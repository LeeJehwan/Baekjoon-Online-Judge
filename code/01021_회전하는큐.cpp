#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int tar;
		cin >> tar;
		int idx = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == tar) {
				idx = j;
				break;
			}
		}

		ans += min(idx, int(v.size() - idx));
		rotate(v.begin(), v.begin() + idx, v.end());
		v.erase(v.begin());
	}
	cout << ans << endl;
}