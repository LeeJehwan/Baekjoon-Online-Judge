#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 , 0, 1, -1 };
int chk[105][105];
char picture[105][105];
int n;

void bfs(int sx, int sy) {
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	chk[sx][sy] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx <= 0 || nx > n || ny <= 0 || ny > n)
				continue;
			if (chk[nx][ny] != 0)
				continue;
			if (picture[x][y] != picture[nx][ny])
				continue;

			chk[nx][ny] = 1;
			q.push(make_pair(nx, ny));
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> picture[i][j];
		}
	}
	

	//일반인
	int count1 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chk[i][j] == 0) {
				count1++;
				bfs(i, j);
			}
		}
	}
	
	//적록색약 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (picture[i][j] == 'G')
				picture[i][j] = 'R';
			
			//chk배열 초기화
			chk[i][j] = 0;
		}
	}

	int count2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chk[i][j] == 0) {
				count2++;
				bfs(i, j);
			}
		}
	}
	
	cout << count1 << " " << count2 << endl;
}