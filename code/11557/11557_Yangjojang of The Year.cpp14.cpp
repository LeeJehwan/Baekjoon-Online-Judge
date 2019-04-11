#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, string>> v;
		for (int i = 0; i < n; i++) {
			string tmps;
			int tmp;
			cin >> tmps;
			cin >> tmp;
			v.push_back({ tmp,tmps });
		}

		sort(v.begin(), v.end());
		cout << v[n - 1].second << '\n';

	}
}