#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;

	string cam = "CAMBRIDGE";

	int len1 = s.size();
	int len2 = cam.size();
	string ans;
	bool ok = true;
	for (int i = 0; i < len1; i++) {
		ok = true;
		for (int j = 0; j < len2; j++) {
			if (s[i] == cam[j]) {
				ok = false;
				break;
			}
		}
		if (ok)
			ans += s[i];

	}
	cout << ans << endl;
}