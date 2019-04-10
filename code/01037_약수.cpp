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

int Min(int arr[], int len) {
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int main() {
	int arr[50] = { 0 };
	int num, min, max;

	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	max = Max(arr, num);
	min = Min(arr, num);
	cout << max * min << endl;
	return 0;
}