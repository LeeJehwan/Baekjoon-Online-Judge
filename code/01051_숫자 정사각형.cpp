#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define endl '\n'

int map[51][51];
int ans[51][51];
int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
			ans[i][j] = 1;
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || j == 1) continue;
			int size = 0;
			while (1) {
				size++;
				if (i - size == 0) break;
				if (j - size == 0) break;
				if (map[i][j] != map[i - size][j]) continue;
				if (map[i][j] != map[i][j - size]) continue;
				if (map[i][j] != map[i - size][j - size]) continue;
				ans[i][j] = size + 1;
			}
		}
	}

	int ans_size = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans_size = max(ans_size, ans[i][j]);
		}
	}
	cout << ans_size * ans_size << endl;
}
