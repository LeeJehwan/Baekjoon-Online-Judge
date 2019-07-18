#include <iostream>
#include <string>
using namespace std;

int cnt, ans;
int main() {
	string str;
	cin >> str;
	
	for (int i = 0 ; str[i] != 0; i++){ 
		if (i == 0) {
			cnt++;
			continue;
		}

		if (str[i] == str[i - 1] + 1) {
			cnt++;
		}
		else {
			if (cnt == 3)
				ans++;
			cnt = 1;
		}
	}
	if (cnt == 3) ans++;


	cout << ans << endl;
}