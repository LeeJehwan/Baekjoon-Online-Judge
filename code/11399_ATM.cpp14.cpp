#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


void sort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int arr[1001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n; j> i; j--)
			sum += arr[i];
	}
	cout << sum << endl;
}