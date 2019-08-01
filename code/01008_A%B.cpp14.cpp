#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	double result = (double)num1 / (double)num2;
	printf("%.10f\n", result);
	return 0;
}