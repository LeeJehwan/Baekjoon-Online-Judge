#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int infn[401][401];
char ask[401][401];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int r, g, b;
			cin >> r >> g >> b;
			infn[i][j] = 2126 * r + 7152 * g + 722 * b;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = infn[i][j];
			if (tmp >= 2040000)
				ask[i][j] = 46;
			else if (tmp >= 1530000)
				ask[i][j] = 45;
			else if (tmp >= 1020000)
				ask[i][j] = 43;
			else if (tmp >= 510000)
				ask[i][j] = 111;
			else
				ask[i][j] = 35;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ask[i][j];
		}
		cout << endl;
	}
}