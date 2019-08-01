#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second - i > ans)
			ans = v[i].second - i;
	}
	cout << ans + 1 << endl;
}