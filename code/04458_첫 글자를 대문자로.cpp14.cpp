#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		string s;
		getline(cin,s);
		int a = 'A' - 'a';
		if(s[0] >='a' && s[0] <='z')
			s[0] = s[0] + a;
		cout << s << endl;
	}
}