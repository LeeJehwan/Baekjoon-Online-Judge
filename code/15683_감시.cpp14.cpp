#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int map[10][10];
vector<pair<int, int>> v;
vector<pair<int, int>> v2;
int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0 , 1, 0, -1 };
int ans = 1000;

int cnt(int (*aa)[10]) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (aa[i][j] == 0)
				c++;
		}
	}
	return c;
}


vector<int> gen(int k, int len) {
	vector<int> tmp(len);
	for (int i = 0; i < len; i++) {
		tmp[i] = k & 3;
		k >>= 2;
	}
	return tmp;
}

void simul() {
	for (int k = 0; k < v2.size(); k++) {
		int x = v2[k].first;
		int y = v2[k].second;

		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					break;
				if (map[nx][ny] == 6)
					break;
				if (map[nx][ny] == 0)
					map[nx][ny] = -1;
			}
		}
	}

	
	int len = v.size();
	for (int i = 0; i < (1 << len * 2); i++) {
		vector<int> now = gen(i, len);
		int cp_map[10][10];
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				cp_map[i][j] = map[i][j];

		for (int j = 0; j < len; j++) {
			int dir = now[j];
			int x = v[j].first;
			int y = v[j].second;
			int mode = map[x][y];
			

			if (mode == 1) {
				int nx = x;
				int ny = y;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
			}
			else if (mode == 2) {
				int nx = x;
				int ny = y;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
				dir = (dir + 2) % 4;
				nx = x;
				ny = y;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
			}
			else if (mode == 3) {
				int nx = x;
				int ny = y;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
				nx = x;
				ny = y;
				dir = (dir + 1) % 4;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
			}
			else if (mode == 4)	{
				int nx = x;
				int ny = y;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
				nx = x;
				ny = y;
				dir = (dir + 1) % 4;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
				nx = x;
				ny = y;
				dir = (dir + 2) % 4;
				while (1) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					if (cp_map[nx][ny] == 6)
						break;
					if (cp_map[nx][ny] == 0)
						cp_map[nx][ny] = -1;
				}
			}

		}
		int sum = cnt(cp_map);
		if (ans > sum)
			ans = sum;
	}


	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 4)
				v.emplace_back(i, j);
			if (map[i][j] == 5)
				v2.emplace_back(i, j);
		}
	}
	

	simul();
	cout << ans << endl;

}