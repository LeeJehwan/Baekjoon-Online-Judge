#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

bool chk[105][105];
int dx[4] = { 0, -1, 0 , 1 };
int dy[4] = { 1, 0 , -1 , 0 };
void go(int x, int y, int d, int g) {
	vector<int> dir;
	dir.push_back(d);

	for (int i = 0; i < g; i++) {
		int len = dir.size();
		for (int j = len - 1; j >= 0; j--) {
			int new_dir = (dir[j] + 1) % 4;
			dir.push_back(new_dir);
		}
	}

	chk[y][x] = true;
	for (int a : dir) {
		y += dx[a];
		x += dy[a];
		chk[y][x] = true;
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		go(x, y, d, g);
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (chk[i][j]) {
				if (chk[i][j + 1] && chk[i + 1][j] && chk[i + 1][j + 1])
					ans++;
			}
		}
	}
	cout << ans << endl;
}