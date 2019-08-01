#include <iostream>
using namespace std;

int searchP(int arr[], int len) {
	for (int i = 2; i <= len; i++) {
		if (arr[i] == 1)
			return i;
	}
}


int main() {
	int n, k;
	cin >> n >> k;
	int count = 0;
	int arr[1000] = { 0 };
	for (int i = 2; i <= n; i++)
		arr[i] = 1;
	int p;
	for (int j = 0; j < n; j++) {
		p = searchP(arr, n);
		for (int i = 1; p*i <= n; i++) {
			if (arr[p*i] == 1) {
				count++;
				arr[p*i] = 0;
			}
			if (count == k) {
				cout << p*i << endl;
				return 0;
			}
		}
	}
}