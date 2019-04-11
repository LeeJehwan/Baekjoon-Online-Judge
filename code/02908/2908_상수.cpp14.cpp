#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int num1, num2;
	cin >> num1 >> num2;

	int num3=0, num4=0;
	for (int i = 0; i < 3; i++) {
		num3 += (num1 % 10)*pow(10, 2 - i);
		num1 = num1 / 10;
		num4 += (num2 % 10)*pow(10, 2 - i);
		num2 = num2 / 10;
	}
	int max=num3;
	if (max < num4)
		max = num4;
	cout << max << endl;
}