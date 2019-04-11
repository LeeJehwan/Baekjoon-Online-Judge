#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[1005][1005];

#define endl '\n'
void solve() {
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	long long sum = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
	int cnt = y2 * x2 - (x1-1) * y2 - x2 * (y1-1) + (x1 - 1)*(y1 - 1);
	cout << sum / cnt << endl;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}


	while (k--) {
		solve();
	}
}