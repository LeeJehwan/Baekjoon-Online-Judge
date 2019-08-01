#include <iostream>

using namespace std;
char arr[64][64];

bool check(int x, int y, int n) {
	char fn = arr[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (fn ^ arr[i][j])
				return false;
	return true;
}

void divideConquer(int x, int y, int n) {
	if (check(x, y, n)) {
		cout << arr[x][y];
		return;
	}

	cout << "(";
	n /= 2;
	divideConquer(x, y, n);
	divideConquer(x, y + n, n);
	divideConquer(x + n, y, n);
	divideConquer(x + n, y + n, n);
	cout << ")";
}

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}
	divideConquer(0, 0, num);
	cout << '\n';
}