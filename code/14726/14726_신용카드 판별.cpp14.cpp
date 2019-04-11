#include <iostream>
#include <string>
using namespace std;
#define endl '\n'



void solve() {
	string str;
	cin >> str;

	int len = 16;
	for (int i = 0; i < len; i += 2) {
		int tmp = 2*(str[i] - '0');
		if (tmp >= 10) {
			int q = tmp % 10;
			int s = tmp / 10;
			tmp = q + s;
		}
		str[i] = tmp + '0';
	}

	int sum = 0;
	for (auto x : str) {
		sum += (x - '0');
	}
	if (sum % 10 == 0)
		cout << "T" << endl;
	else
		cout << "F" << endl;

}



int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}