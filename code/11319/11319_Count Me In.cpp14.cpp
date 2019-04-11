#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		string s;
		getline(cin, s);
		int len = s.size();
		int space_len = 0;
		int vol = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= ('a' - 'A');
			if (s[i] == ' ')
				space_len++;
		}
		
		for (int i = 0; i < len; i++) {
			if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] =='I')
				vol++;
		}

		cout << len - space_len - vol << " " << vol << endl;

	}
}

