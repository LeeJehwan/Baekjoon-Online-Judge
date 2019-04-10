#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void acs(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	}
}

void des(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++)
			if (arr[j] < arr[j + 1])
				swap(arr[j], arr[j + 1]);
	}
}


int main() {
	int arr1[50];
	int arr2[50];
	int sum = 0;
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> arr1[i];
	for (int i = 0; i < num; i++)
		cin >> arr2[i];

	des(arr2, num);
	acs(arr1, num);

	for (int i = 0; i < num; i++)
		sum += arr1[i] * arr2[i];
	cout << sum << endl;

}