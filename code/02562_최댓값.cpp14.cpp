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
	int arr[9];
	int i = 0;
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	int max = Max(arr, 9);
	cout << max<<endl;

	for (i = 0; i < 9; i++)
		if (arr[i] == max)
			break;
	cout << i+1 <<endl;
}