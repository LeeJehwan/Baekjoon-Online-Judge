#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		v[i] = t + v[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		auto l = upper_bound(v.begin(), v.end(), t);
		cout << l - v.begin() -1 << endl;
	}
	
}