#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define endl '\n'

int map[130][130];
int chk[130][130];
int dist[130][130];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct info {
	int x, y, w;
	bool operator < (const info & tmp)const{
		return w > tmp.w;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int cnt = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = INT_MAX;
				chk[i][j] = 1;
			}
		}

		priority_queue<info> pq;
		info tmp = { 1,1,map[1][1] };

		pq.push(tmp);
		dist[1][1] = map[1][1];

		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			if (p.w > dist[p.x][p.y])
				continue;
			chk[p.x][p.y] = true;

			if (p.x == n && p.y == n)
				break;

			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				int nw = p.w + map[nx][ny];

				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
				if (!chk[nx][ny]) continue;
				if (nw < dist[nx][ny]) {
					dist[nx][ny] = nw;
					pq.push(info{ nx,ny,nw });
				}
			}
		}

		cout << "Problem " << cnt++ << ": " << dist[n][n] << endl;
	}

}