#include <iostream>
using namespace std;

int main() {
	int num,count=0;
	cin >> num;
	int a, b;
	int temp = num;

	while (1) {
		b = temp % 10;
		a = temp / 10;
		temp = (b * 10) + (a + b) % 10;
		count++;
		if (temp == num)
			break;
	}
	cout << count << endl;
}