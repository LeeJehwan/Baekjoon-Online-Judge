#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0, c = 1;
	while(n--) {
		int t;
		cin >> t;
		if (t) {a += c;c++;}
		else c = 1;
	}
	cout << a << '\n';
}