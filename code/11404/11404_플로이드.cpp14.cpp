#include <iostream>
#include <algorithm>

using namespace std;
int arr[105][105];
int dp[105][105];

void floyd(int n,int m) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || arr[i][k] == 0 || arr[k][j] == 0)
					continue;
				if (arr[i][j] != 0) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
					continue;
				}
				arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		if (arr[j - 1][k - 1] != 0) {
			int tmp;
			cin >> tmp;
			arr[j - 1][k - 1] = min(tmp, arr[j - 1][k - 1]);
			continue;
		}
		cin >> arr[j - 1][k - 1];
	}
	floyd(n,m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j]<<" ";
		cout << endl;
	}
}