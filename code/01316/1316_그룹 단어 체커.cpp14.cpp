#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int chk[101];
int main() {
	int t;
	cin >> t;
	int ans = 0;
	while (t--) {
		string s;
		cin >> s;
		memset(chk, 0, sizeof(chk));
		int len = s.size();
		bool con = false;


		for (int i = 0; i < len; i++) {
			if (chk[s[i] - 'a'] == true) {
				if (i != 0 && s[i] != s[i - 1]) {
					con = true;
					break;
				}
			}
			else
				chk[s[i] - 'a'] = true;
		}

		if (!con)
			ans++;
	}
	cout << ans << endl;

}

