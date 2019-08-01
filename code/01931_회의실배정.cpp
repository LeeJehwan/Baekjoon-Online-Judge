#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return make_tuple(p1.second, p1.first) < make_tuple(p2.second, p2.first);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);
	int ans = 1;
	int time = v[0].second;
	for (int i = 1; i < n; i++) {
		if (time <= v[i].first) {
			ans++;
			time = v[i].second;
		}
	}
	cout << ans << endl;

}