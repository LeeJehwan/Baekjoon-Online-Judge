#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
	int n, m;
	cin >> n >> m;

	string s;
	while (n--) {
		cin >> s;
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}