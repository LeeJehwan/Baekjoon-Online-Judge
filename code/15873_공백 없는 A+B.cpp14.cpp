#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	if (s.size() == 4) {
		cout << 20 << endl;
		return 0;
	}

	if (s.size() == 2) {
		int a = s[0] - '0';
		int b = s[1] - '0';
		cout << a + b << endl;
		return 0;
	}

	if (s.size() == 3) {
		if (s[0] == '1' && s[1] == '0') {
			int t = s[2] - '0';
			cout << t + 10 << endl;
		}
		else {
			int t = s[0] - '0';
			cout << t + 10 << endl;
		}
	}
}