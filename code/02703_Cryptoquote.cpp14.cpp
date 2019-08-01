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
	while (t--) {
		getchar();
		string s;
		getline(cin, s);

		char arr[26];
		for (int i = 0; i < 26; i++) {
			cin >> arr[i];
		}

		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = arr[s[i] - 'A'];
			}
		}
		cout << s << endl;
	}
}