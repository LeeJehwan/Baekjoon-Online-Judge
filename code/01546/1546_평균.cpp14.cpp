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
	int n;
	int arr[1000];
	double arr2[1000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int max = Max(arr, n);

	for (int i = 0; i < n; i++)
		arr2[i] = (double)arr[i] / max * 100;
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr2[i];
	printf("%.2lf\n", sum / n);
	
	return 0;
}
