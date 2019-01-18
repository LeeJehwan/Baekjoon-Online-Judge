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
		int a, b;
		cin >> a >> b;
		reverse(v.begin() + a - 1, v.begin() + b);
	}
	for (auto x : v)
		cout << x << " ";
}