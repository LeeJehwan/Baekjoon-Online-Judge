#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		string str;
		getline(cin, str);

		int len = str.size();

		for (int i = 0; i < len; i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
		}

		bool key = true;

		int mid = len / 2;
		for (int i = 0; i < mid; i++) {
			if (str[i] != str[len - i -1 ]) {
				key = false;
				break;
			}
		}
		if (key)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

}