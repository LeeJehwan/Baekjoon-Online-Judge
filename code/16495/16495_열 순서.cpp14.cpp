#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int len = s.size();
	long long sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum * 26 + (s[i] - 'A'+1);
	}
	cout << sum << endl;
}