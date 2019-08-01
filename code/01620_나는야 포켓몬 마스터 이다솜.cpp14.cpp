#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
#define endl '\n'


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	unordered_map<string, string> map1;
	unordered_map<string, int> map2;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		map1[to_string(i)] = str;
		map2[str] = i;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') {
			cout << map2[s] << endl;
		}
		else {
			cout << map1[s] << endl;
		}
	}

}