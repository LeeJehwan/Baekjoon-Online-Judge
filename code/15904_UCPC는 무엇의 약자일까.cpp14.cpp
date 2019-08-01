#include <iostream>
#include <string>
using namespace std;

bool b1, b2, b3, b4;
int main() {
	string str;
	getline(cin, str);

	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == 'U')
			b1 = true;

		if (str[i] == 'C' && b1)
			b2 = true;

		if (str[i] == 'P' && b2)
			b3 = true;

		if (str[i] == 'C' && b3)
			b4 = true;
	}

	if (b4)
		cout << "I love UCPC" << endl;
	else
		cout << "I hate UCPC" << endl;

}