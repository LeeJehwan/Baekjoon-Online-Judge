#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	if (num == 0) {
		cout << 1 << endl;
		return 0;
	}

	int arr[10] = { 0 };
	while (1) {
		if (num % 10 == 0 && num / 10 == 0)
			break;
		arr[num % 10]++;
		num = num / 10;
	}
	arr[6] = (arr[6] + arr[9])/2+ (arr[6] + arr[9])%2;
	arr[9] = 0;

	int max = 0;
	for (int i = 0; i < 10; i++)
		if (max < arr[i])
			max = arr[i];
	cout << max << endl;


}