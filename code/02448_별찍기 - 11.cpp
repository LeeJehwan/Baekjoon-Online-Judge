#include <iostream>
using namespace std;

char map[3072][6144];

void star(int x, int y) {
	map[x][y + 2] = '*';
	map[x + 1][y + 1] = map[x + 1][y + 3] = '*';
	for (int i = y; i < y + 5; i++)
		map[x + 2][i] = '*';
}

void print(int n, int x, int y) {
	if (n == 3) {
		star(x, y);
		return;
	}
	int k = n / 2;
	print(k, x + k, y);
	print(k, x , y + k);
	print(k, x + k, y + 2 * k);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	print(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n; j++) {
			if (map[i][j] == 0)
				map[i][j] = ' ';
			cout << map[i][j];
		}
		cout << endl;
	}
}