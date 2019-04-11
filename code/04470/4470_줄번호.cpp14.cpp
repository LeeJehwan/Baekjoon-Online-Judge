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
	int count = 1;
	while (t--) {
		string s;
		getline(cin, s);

		cout << count++ << ". " << s << endl;
	}
}