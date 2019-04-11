#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int len = str.size();
		long long ans = 0;
		int mul = 1;
		for (int i = len-1; i >= 0; i--) {
			ans += (str[i]-'0') * mul;
			mul *= 2;
		}
		cout << ans << '\n';
	}
}