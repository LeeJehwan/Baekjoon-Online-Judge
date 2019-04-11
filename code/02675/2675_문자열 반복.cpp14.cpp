#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int r;
		cin >> r;
		string s;
		cin >> s;
		string ans;

		int len = s.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < r; j++) {
				ans += s[i];
			}
		}
		cout << ans << '\n';
	}
}