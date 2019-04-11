#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	do {
		for (auto x : v)
			cout << x << " ";
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}