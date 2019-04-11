#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	map<string, int> ma;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		ma[tmp] = 1;
	}

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		ma[tmp] += 1;
	}

	int ans = 0;
	for (auto x : ma) {
		if (x.second == 2)
			ans++;
	}

	cout << ans << endl;

	for (auto x : ma) {
		if (x.second == 2)
			cout << x.first << '\n';
	}



}