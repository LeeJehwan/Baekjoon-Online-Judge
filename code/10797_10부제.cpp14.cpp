#include <iostream>
using namespace std;




int main() {
	int num;
	cin >> num;
	int num2;
	int count = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num2;
		if (num == num2)
			count++;
	}

	cout << count << endl;

}