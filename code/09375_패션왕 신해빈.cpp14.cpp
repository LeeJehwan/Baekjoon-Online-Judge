#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <set>
using namespace	std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	while (t--) {
		unordered_map<string, int> m;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m.count(s2))
				m[s2]++;
			else
				m[s2] = 1;
		}
		int ans = 1;
		for (auto a : m) {
			ans *= a.second + 1;
		}
	
		cout << ans - 1 << endl;
	}
}