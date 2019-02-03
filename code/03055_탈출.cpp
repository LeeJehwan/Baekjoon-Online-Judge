#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

char map[51][51];
int chk[51][51];
int dx[] = { -1, 1, 0 ,0 };
int dy[] = { 0, 0, 1, -1 };
struct que{
	int x, y;
	char now;
};

int main() {
	int n, m;
	cin >> n >> m;

	queue<que> q;
	int sx, sy, ex, ey;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sx = i;
				sy = j;
				chk[i][j] = 1;
			}
			else if (map[i][j] == '*') 
				q.push({ i,j,'W' });
			else if (map[i][j] == 'D') {
				ex = i;
				ey = j;
			}
			else if (map[i][j] == 'X') 
				map[i][j] = '*';
		}
	}

	q.push({ sx,sy,'D'});

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		char now = q.front().now;
		q.pop();

		if (map[x][y] == 'D')
			break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (now == 'D') {
					if (map[nx][ny] != '*' && !chk[nx][ny]) {
						chk[nx][ny] = chk[x][y] + 1;
						q.push({ nx,ny,'D' });
					}
				}
				else {
					if (map[nx][ny] == '.' || map[nx][ny] == 'S') {
						map[nx][ny] = '*';
						q.push({ nx,ny,'W' });
					}
				}
			}
		}
	}

	if (chk[ex][ey] != 0) {
		cout << chk[ex][ey]-1 << endl;
	}
	else
		cout << "KAKTUS" << endl;
}