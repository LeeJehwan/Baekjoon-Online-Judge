#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int key = (s[0] ^ 'C');
	for (int i = 0; i < s.size(); i++)
		s[i] ^= key;
	cout << s << endl;
}