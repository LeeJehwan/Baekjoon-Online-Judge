#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int map[11][11];
int chk[11][11];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0 , 1, -1 };
int main() {
	int s, e;
	cin >> s >> e;
	s--; e--;
	vector<pair<int,int>> v;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char ch;
			cin >> ch;
			if (ch == 'x')
				map[i][j] = 0;
			else {
				map[i][j] = 1;
				v.push_back({ i,j });
			}
		}
	}


	for (auto t : v) {
		int x = t.first;
		int y = t.second;

		for (int i = 0; i < 10; i++) {
			map[x][i] = 1;
			map[i][y] = 1;
		}
	}

	queue<pair<int, int>> q;
	q.push({ s,e });
	chk[s][e] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (map[x][y] == 0) {
			cout << chk[x][y] - 1 << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= 10) continue;
			if (ny < 0 || ny >= 10) continue;
			if (chk[nx][ny]) continue;

			chk[nx][ny] = chk[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}


