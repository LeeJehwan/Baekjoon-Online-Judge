#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &v1, const pair<int, int> &v2) {
	return make_pair(v1.second, v1.first) < make_pair(v2.second, v2.first);
}



int main() {
	vector<pair<int, int>> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);
	for (auto x : v) {
		cout << x.first << " " << x.second << '\n';
	}
}