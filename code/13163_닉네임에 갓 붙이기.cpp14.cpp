#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace	std;
#define endl '\n'


int main() {
	int t;
	cin >> t;
	getchar();
	
	while (t--) {
		string s;
		getline(cin, s);

		string ans = "god";
		int len = s.size();
		bool go = false;
		for (int i = 0; i < len; i++) {
			if (s[i] == ' ')
				go = true;
			if (go && s[i] != ' ')
				ans += s[i];
		}
		cout << ans << endl;
	}
}