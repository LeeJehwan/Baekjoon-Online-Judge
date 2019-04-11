#include <iostream>
using namespace std;

int Max(int arr[], int len) {
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int main() {
	int arr[8];
	int sum = 0;
	int num;
	for (int i = 0; i < 8; i=i+2) {
		cin >> num;
		sum -= num;
		arr[i] = sum;
		cin >> num;
		sum += num;
		arr[i + 1] = sum;
	}
	cout << Max(arr, 8) << endl;
	return 0;

}