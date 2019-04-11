#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	while (1) {
		string s;
		getline(cin, s);
		if (s == "*")
			break;
		int alpa[26] = { 0 };
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == ' ')
				continue;
			alpa[s[i] - 'a']++;
		}
		bool NO = false;
		for (auto x : alpa) {
			if (x == 0) {
				cout << "N" << endl;
				NO = true;
				break;
			}
		}
		if (!NO)
			cout << "Y" << endl;
	}
}