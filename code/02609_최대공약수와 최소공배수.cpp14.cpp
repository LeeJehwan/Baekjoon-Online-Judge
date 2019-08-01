#include <iostream>
using namespace std;


int find_gcd(int num1, int num2) {
	int max, min;
	if (num1 > num2) {
		max = num1;
		min = num2;
	}
	else {
		max = num2;
		min = num1;
	}

	int r;
	while (1) {
		r = max%min;
		if (r == 0)
			break;
		max = min;
		min = r;
	}
	return min;
}

int main() {
	int num1, num2;
	int gcd;
	cin >> num1 >> num2;
	gcd = find_gcd(num1, num2);
	int LSW = num1*(num2 / gcd);

	cout << gcd << endl;
	cout<<LSW << endl;


}