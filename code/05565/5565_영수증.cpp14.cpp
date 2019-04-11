#include <iostream>
using namespace std;




int main() {
	int num;
	cin >> num;
	int num2;
	int count = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num2;
		num -= num2;
	}

	cout << num << endl;

}