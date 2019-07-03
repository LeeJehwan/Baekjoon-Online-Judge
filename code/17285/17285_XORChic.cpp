#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	string s;
	cin >> s;
	char ch = s[0];
	int key = 0;
	while (1) {
		if ((key^ch) == 'C')
			break;
		key++;
	}
	for (int i = 0; i < s.size(); i++)
		s[i] ^= key;
	cout << s << endl;

}