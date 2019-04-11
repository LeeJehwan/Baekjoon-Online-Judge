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

void input() {
	int arr[20];
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	int max = Max(arr, num);
	int min = Min(arr, num);
	cout << (max - min) * 2 << endl;
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		input();
	}
}