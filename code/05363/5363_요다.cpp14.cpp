#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		getchar();
		string str;
		getline(cin, str);

		cout << str << " " << s1 << " " << s2 << endl;
	}
}