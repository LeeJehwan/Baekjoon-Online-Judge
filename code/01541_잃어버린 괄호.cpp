#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	string str;
	cin >> str;

	int len = str.size();
	long long ans = 0;
	
	int tmp = 0;
	bool flag = false;
	for (int i = 0; i < len; i++) {
		if (str[i] == '+') {
			if (flag) {
				ans -= tmp;
			}
			else {
				ans += tmp;
			}
			tmp = 0;
		}
		else if(str[i] == '-'){
			if (flag) {
				ans -= tmp;
			}
			else {
				ans += tmp;
				flag = true;
			}
			tmp = 0;
		}
		else {
			tmp = tmp * 10 + str[i] - '0';
		}
	}
	
	if (flag)
		ans -= tmp;
	else
		ans += tmp;

	cout << ans << endl;
}