#include <iostream>
#include <string>
using namespace std;

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;

		if (a + c == 2 * b)
			cout << "AP" << " " << 2 * c - b << endl;
		else
			cout << "GP" << " " << c*(b / a) << endl;
	}
}