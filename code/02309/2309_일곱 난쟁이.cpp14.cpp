#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	}
}
int main() {
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sum -= 100;
	int a, b;
	for(int i=0;i<9;i++)
		for(int j=i;j<9;j++)
			if (i != j && arr[i] + arr[j] == sum) {
				a = i;
				b = j;
				break;
			}
	int temp = arr[b];
	for (int i = a; i < 8; i++)
		arr[i] = arr[i + 1];
	for (int i = 0; i < 8; i++)
		if (temp == arr[i])
			b = i;
	for (int i = b; i < 7; i++)
		arr[i] = arr[i + 1];
	sort(arr, 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << endl;
}