#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}

	sort(v.begin(), v.end());
	for (auto x: v) {
		cout << x.second << " " << x.first << '\n';
	}
}