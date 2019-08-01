#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define endl '\n'

int map[5][5];
int main() {
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << (n*m)); i++) {
		int sum = 0;
		for (int a = 0; a < n; a++) {
			int cur = 0;
			for (int b = 0; b < m; b++) {
				int t = a * m + b;
				if ((i & (1 << t)) == 0) {
					cur = cur * 10 + map[a][b];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int a = 0; a < m; a++) {
			int cur = 0;
			for (int b = 0; b < n; b++) {
				int t = b * m + a;
				if ((i & (1 << t)) != 0) {
					cur = cur * 10 + map[b][a];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;
}