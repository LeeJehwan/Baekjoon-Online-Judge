#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'


bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
		cout << x << endl;
}