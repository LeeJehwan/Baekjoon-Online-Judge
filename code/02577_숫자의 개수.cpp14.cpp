#include <iostream>
using namespace std;

int main() {
	int arr[10] = { 0 };

	int a, b, c;
	cin >> a >> b >> c;
	int sum = a*b*c;
	while(1) {
		if (sum / 10 == 0 && sum%10==0)
			break;
		arr[sum % 10]++;
		sum = sum / 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
}