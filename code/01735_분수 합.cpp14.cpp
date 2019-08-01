#include <iostream>

using namespace std;

int find_gcd(int num1, int num2) {
	int r;
	int max = num1 >= num2 ? num1 : num2;
	int min = num1 >= num2 ? num2 : num1;
	num1 = max;
	num2 = min;

	while (1) {
		r = num1%num2;
		if (r == 0)
			break;
		num1 = num2;
		num2 = r;
	}
	return num2;
}


int main() {
	int num1, num2, num3, num4;
	cin >> num1 >> num2 >> num3 >> num4;
	int gcd= find_gcd(num2, num4);
	int LCM = num2*(num4 / gcd);
	
	
	int temp_num1, temp_num3;

	temp_num1 = LCM / num2;
	temp_num3 = LCM / num4;
	num1 = num1*temp_num1;
	num3 = num3*temp_num3;

	int numerator = num1 + num3;
	
	int gcd2 = find_gcd(numerator, LCM);
	numerator = numerator / gcd2;
	LCM = LCM / gcd2;
	cout << numerator << " " << LCM << endl;
	return 0;

	
}