#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << a + b << endl;
	}
}