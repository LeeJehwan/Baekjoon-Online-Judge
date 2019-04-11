#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int gong = 1;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x == gong || y == gong) {
			gong = x + y - gong;
		}

	}
	cout << gong << endl;
}

