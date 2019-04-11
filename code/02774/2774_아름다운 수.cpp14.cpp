#include <iostream>
using namespace std;


int main() {
	int a;
	cin >> a;
	for (int j = 0; j < a; j++) {
		int arr[10] = { 0 };
		int num;

		cin >> num;

		while (1) {
			if (num / 10 == 0 && num % 10 == 0)
				break;
			arr[num % 10]++;
			num = num / 10;

		}
		int count = 0;
		for (int i = 0; i < 10; i++)
			if (arr[i] > 0)
				count++;
		cout << count << endl;

	}
}