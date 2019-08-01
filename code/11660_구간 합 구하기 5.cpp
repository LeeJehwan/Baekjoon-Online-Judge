#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAX 1030

int map[MAX][MAX];
long long sum[MAX][MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1] << endl;
	}



}