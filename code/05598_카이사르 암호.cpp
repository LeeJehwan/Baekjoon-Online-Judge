#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int len = s.size();
	for (int i = 0; i < len; i++) {
		s[i] = s[i] - 3;
		if (s[i] < 'A')
			s[i] += 26;
	}
	cout << s << endl;
}