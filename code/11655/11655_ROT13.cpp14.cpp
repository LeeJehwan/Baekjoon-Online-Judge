#include <iostream>
#include <string>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	int len = s.size();

	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] + 13 > 'z' || s[i] + 13 <= 0)
				s[i] -= 26;
			s[i] += 13;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 13;
			if (s[i] > 'Z')
				s[i] -= 26;
		}

	}

	cout << s << endl;

}