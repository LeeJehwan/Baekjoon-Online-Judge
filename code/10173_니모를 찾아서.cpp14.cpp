#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
	while (1) {
		string str;
		string str2 = "NEMO";
		getline(cin, str);

		if (str == "EOI")
			break;

		int size = str.size();
		for (int i = 0; i < size; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				str[i] = str[i]- ('a' - 'A');
			}
		}
		int a = str.find(str2);
		if (a == -1)
			cout << "Missing" << endl;
		else
			cout << "Found" << endl;
	}
}