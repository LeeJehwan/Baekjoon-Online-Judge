#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool chk(int a, int b, char c) {
	if (c == '<') {
		if (a < b)
			return true;
		else
			return false;
	}
	else if (c == '>') {
		if (a > b)
			return true;
		else
			return false;
	}
}

char c[10];
int main() {
	int n;
	cin >> n;
	int len = n + 1;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	vector<int> max_v;
	vector<int> min_v;
	for (int i = 0; i < len; i++) {
		max_v.push_back(9 - i);
		min_v.push_back(i);
	}

	bool ok = false;
	do {
		for (int i = 0; i < n; i++) {
			if (!chk(max_v[i], max_v[i + 1], c[i])) {
				break;
			}
			if (i == n - 1)
				ok = true;
		}
		if (ok)
			break;
	} while (prev_permutation(max_v.begin(), max_v.end()));
	ok = false;

	do {
		for (int i = 0; i < n; i++) {
			if (!chk(min_v[i], min_v[i + 1], c[i])) {
				break;
			}
			if (i == n - 1)
				ok = true;
		}
		if (ok)
			break;
	} while (next_permutation(min_v.begin(), min_v.end()));


	for (auto x : max_v)
		cout << x;
	cout << '\n';
	for (auto x : min_v)
		cout << x;
	cout << '\n';

}