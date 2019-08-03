#include <iostream>
#include <string>
using namespace std;

int main() {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		int mode;
		if (b % a == 0)
			mode = 0;
		else if (a % b == 0)
			mode = 1;
		else
			mode = 2;
		string s[3] = { "factor", "multiple", "neither" };
		cout << s[mode] << endl;
	}
}