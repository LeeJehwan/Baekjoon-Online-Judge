#include <iostream>
using namespace std;
#define endl '\n'
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	else {
		cout << b - a << " " << b << endl;
	}
}