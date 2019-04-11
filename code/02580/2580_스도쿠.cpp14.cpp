#include <iostream>
using namespace std;
#define endl '\n'

int n = 9;
int a[9][9];
bool c1[9][9];
bool c2[9][9];
bool c3[9][9];

int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

bool go(int z) {
	if (z == 81) {
		for (int i = 0; i < n; i++) {
			for(int j=0;j<n ;j++){
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
		return true;
	}

	int x = z / 9;
	int y = z % 9;
	if (a[x][y] != 0)
		return go(z + 1);

	for (int i = 1; i <= 9; i++) {
		if (a[x][y] == 0 && c1[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i] == 0) {
			a[x][y] = i;
			c1[x][i] = true;
			c2[y][i] = true;
			c3[square(x, y)][i] = true;
			
			if (go(z + 1)) return true;

			a[x][y] = 0;
			c1[x][i] = false;
			c2[y][i] = false;
			c3[square(x, y)][i] = false;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				c1[i][a[i][j]] = true;
				c2[j][a[i][j]] = true;
				c3[square(i,j)][a[i][j]] = true;
			}
		}
	}
	go(0);


}