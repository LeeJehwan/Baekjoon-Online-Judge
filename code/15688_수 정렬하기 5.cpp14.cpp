#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	for (auto x : v)
		cout << x << endl;
}