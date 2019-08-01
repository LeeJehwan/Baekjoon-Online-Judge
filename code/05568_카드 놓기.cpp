#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int card[15];
set<string> s;
vector<int> v;
int n, k;

void solve() {
	string str = "";
	vector<pair<int, int>> tmp;
	for (int i = 0; i < n; i++) {
		tmp.push_back({ v[i], i });
	}
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < n; i++) {
		if (tmp[i].first)
			str += to_string(card[tmp[i].second]);
	}
	s.insert(str);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n - k; i++) {
		v.push_back(0);
	}
	for (int i = 1; i <= k; i++) {
		v.push_back(i);
	}

	do {
		solve();

	} while (next_permutation(v.begin(), v.end()));
	cout << s.size() << endl;

}