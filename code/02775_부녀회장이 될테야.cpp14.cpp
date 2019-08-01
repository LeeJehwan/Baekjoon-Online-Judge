#include <iostream>
using namespace std;

int main() {
	int arr[15][15] = { 0 };

	for (int i = 0; i < 15; i++) {
		arr[i][1] = 1;
		arr[0][i] = i;
	}
	for (int i = 1; i < 15; i++)
		for (int j = 2; j < 15; j++)
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int k, n;
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}
}
