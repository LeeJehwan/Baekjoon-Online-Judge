#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int input[51][51];
int chk[51][51];
//아래 오른 위 왼
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[4] = { 8, 4, 2, 1 };
vector<int> dec_to_bit(int num) {
	vector<int> v;

	for (int i = 0; i < 4; i++) {
		if (num / arr[i]) {
			v.push_back(1);
			num -= arr[i];
		}
		else
			v.push_back(0);
	}
	return v;
}

int bfs(int sx, int sy) {
	queue<pair<int,int>> q;
	q.push({ sx,sy });
	chk[sx][sy] = 1;

	int area = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		vector<int> v = dec_to_bit(input[x][y]);
		area++;

		for (int i = 0; i < 4; i++) {
			if (v[i] == 0) continue;

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (chk[nx][ny] != 0) continue;

			chk[nx][ny] = 1;
			q.push({ nx,ny });

		}
	}
	return area;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//갈 수 있는곳만
			int tmp;
			cin >> tmp;
			input[i][j] = 15 - tmp;
		}
	}
	
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!chk[i][j]) {
				ans1++;
				ans2 = max(ans2, bfs(i, j));
			}
		}
	}

	memset(chk, 0, sizeof(chk));
	int ans3 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vector<int> v = dec_to_bit(input[i][j]);
			for (int k = 0; k < 4; k++) {
				if (v[k] == 1) continue;
				input[i][j] += arr[k];
				memset(chk, 0, sizeof(chk));
				ans3 = max(ans3, bfs(i, j));
				input[i][j] -= arr[k];
			}
		}
	}


	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
}