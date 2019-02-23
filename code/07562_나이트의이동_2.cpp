#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define endl '\n'

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
int chk[301][301];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sx, sy;
		cin >> sx >> sy;
		int ex, ey;
		cin >> ex >> ey;
		memset(chk, -1, sizeof(chk));
		queue<pair<int,int>> q;
		q.push({ sx,sy });
		chk[sx][sy] = 0;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			if (p.first == ex && p.second == ey)
				break;
			for (int i = 0; i < 8; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (chk[nx][ny] != -1) continue;
				chk[nx][ny] = chk[p.first][p.second] + 1;
				q.push({ nx,ny });
			}
			
		}
		cout << chk[ex][ey] << endl;
	}
}