#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

char arr[2000][2000];
void print(int n, int x, int y) {
	if (n == 0)
		arr[x][y] = '*';
	else {
		int k = 1 << (n - 1);
		print(n - 1, x, y);
		print(n - 1, x + k, y);
		print(n - 1, x, y + k);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	print(n, 1, 1);
	int k = 1 << n;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k - i + 1; j++) {
			if (arr[i][j] == 0)
				arr[i][j] = ' ';
			cout << arr[i][j];
		}
		cout << endl;
	}

}