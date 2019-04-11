#include <iostream>
using namespace std;
int arr[101][101];

int main() {
	int num;
	cin >> num;
	int xarr[100];
	int yarr[100];
	int count = 0;
	for (int i = 0; i < num; i++) {
		cin >> xarr[i] >> yarr[i];
	}
	for (int n = 0; n < num; n++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[xarr[n]+i][yarr[n]+j]++;
			}
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] > 0)
				count++;
		}
	}

	cout << count << endl;
}