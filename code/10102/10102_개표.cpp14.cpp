#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int A = 0, B = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A')
			A++;
		if (s[i] == 'B')
			B++;
	}
	if (A == B)
		cout << "Tie" << endl;
	else if (A > B)
		cout << "A" << endl;
	else
		cout << "B" << endl;
}