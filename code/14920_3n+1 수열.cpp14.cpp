#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 1;

	if (n == 1) {
		cout << count << endl;
		return 0;
	}
	while (1) {
		if (n % 2 == 0) 
			n = n / 2;
		else 
			n = 3 * n + 1;
		count++;
		if (n == 1)
			break;
	}

	cout << count << endl;

}