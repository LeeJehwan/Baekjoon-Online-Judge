#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		list<char> ans;
		auto it = ans.begin();
		for (auto x: s) {
			if (x == '<') {
				if (it == ans.begin()) continue;
				--it;
			}
			else if (x == '>') {
				if (it == ans.end()) continue;
				++it;
			}
			else if (x == '-') {
				if (it == ans.begin()) continue;
				--it;
				it = ans.erase(it);
			}
			else {
				ans.insert(it, x);
			}

		}
		for (auto x : ans)
			cout << x;
		cout << endl;
	}
}