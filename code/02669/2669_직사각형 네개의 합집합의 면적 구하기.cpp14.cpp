#include <iostream>
using namespace std;

int arr[101][101];

void square(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			arr[i][j] = 1;
}

int main() {
	for (int i = 0; i < 4; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		square(x1, y1, x2, y2);
	}
	int sum = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			sum += arr[i][j];
		}
	}
	cout << sum << endl;
}