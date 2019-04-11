#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int arr[50];
	arr[0] = 0;
	for (int i = 1; i < 50; i++)
		arr[i] = 1 + (i*(i - 1)) / 2;

	int arr2[1001];
	arr2[0] = 0;
	int count = 0;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < i;j++,count++) {
			arr2[count] = i;
			if (count == 1000)
				break;
		}
	}

	int sum1 = 0, sum2 = 0;
	int num1, num2;
	cin >> num1 >> num2;
	for (int i = 0; i < num1-1; i++)
		sum1 += arr2[i];
	for (int i = 0; i < num2; i++)
		sum2 += arr2[i];
	cout << sum2 - sum1 << endl;

	return 0;
}