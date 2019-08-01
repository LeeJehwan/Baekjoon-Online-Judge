#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int b;
	cin >> str;
	cin >> b;

	int len = str.size();
	long long ans = 0;
	long long mul = 1;
	for (int i = len - 1; i >= 0; i--) {
		if (i != len - 1)
			mul *= b;
		if (str[i] <= '9' && str[i] >= '0')
			ans += mul*(str[i] - '0');
		else
			ans += mul*(str[i] - 'A' + 10);
	}

	cout << ans << '\n';
}