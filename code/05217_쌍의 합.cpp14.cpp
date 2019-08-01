#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> v;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (i == j) continue;
				if (i + j == n)
					v.push_back(make_pair(i, j));

			}
		}

		cout << "Pairs for " << n << ": ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << " " << v[i].second;
			if (i + 1 == v.size())
				cout << endl;
			else
				cout << ", ";
		}
		if (v.size() == 0)
			cout << endl;

	}
}