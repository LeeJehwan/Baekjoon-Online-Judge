#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	bool a = next_permutation(v.begin(), v.end());
	if (!a) {
		cout << -1 << endl;
	}
	else {
		for (auto x : v)
			cout << x << " ";
		cout << endl;
	}
}