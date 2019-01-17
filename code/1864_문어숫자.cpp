#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int arr[10];

int conv(char ch) {
	int ans;
	if (ch == '-')
		ans = 0;
	else if (ch == '\\')
		ans = 1;
	else if (ch == '(')
		ans = 2;
	else if (ch == '@')
		ans = 3;
	else if (ch == '?')
		ans = 4;
	else if (ch == '>')
		ans = 5;
	else if (ch == '&')
		ans = 6;
	else if (ch == '%')
		ans = 7;
	else if (ch == '/')
		ans = -1;

	return ans;
}


int main() {
	while (1) {
		string s;
		cin >> s;
		if (s == "#")
			break;
	
		int len = s.size();

		for (int i = 0; i < len; i++) {
			arr[i] = conv(s[i]);
		}
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum = sum * 8 + arr[i];
		}
		cout << sum << endl;
	}
}