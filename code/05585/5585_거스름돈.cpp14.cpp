#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int sum = 1000;
	sum -= num;
	int count = 0;
	while (1) {
		int temp = sum / 500;
		if (temp == 0)
			break;
		count += temp;
		sum -= 500 * temp;
	}
	while (1) {
		int temp = sum / 100;
		if (temp == 0)
			break;
		count += temp;
		sum -= 100 * temp;
	}
	while (1) {
		int temp = sum / 50;
		if (temp == 0)
			break;
		count += temp;
		sum -= 50 * temp;
	}
	while (1) {
		int temp = sum / 10;
		if (temp == 0)
			break;
		count += temp;
		sum -= 10 * temp;
	}
	while (1) {
		int temp = sum / 5;
		if (temp == 0)
			break;
		count += temp;
		sum -= 5 * temp;
	}
	while (1) {
		int temp = sum / 1;
		if (temp == 0)
			break;
		count += temp;
		sum -= 1 * temp;
	}
	cout << count << endl;
}