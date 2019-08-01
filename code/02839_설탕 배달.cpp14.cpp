#include <iostream>
using namespace std;

int min(int arr[], int len) {
	int min = arr[0];
	for (int i = 0; i < len; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}
int main() {
	int num;
	cin >> num;

	int arr[2000];
	int result;
	int k = 0;
	for (int i = 0; i <= num / 3; i++) {
		for (int j = 0; j <= num / 5; j++) {
			result = 3 * i + 5 * j;
			if (result > num)
				break;
			if (result == num)
				arr[k++] = i + j;
		}
	}
	if (k == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout<<min(arr, k)<<endl;
}