#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 1; i <= n; i++) {
		v[i - 1] = i;
	}

	while (m--) {
		int s, m, e;
		cin >> s >> e >> m;
		rotate(v.begin() + s - 1, v.begin() + m - 1, v.begin() + e);
	}
	for (auto x : v)
		cout << x << " ";
	
}