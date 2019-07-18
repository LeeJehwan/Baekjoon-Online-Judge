#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
#define endl '\n'
#define INF 1e9

int n, m;
int mat[501][501];
int dist[501];
bool chk[501];
vector<int> from[501];
void init(bool flag) {
	if (flag) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++) {
			from[i].clear();
		}
	}
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
	}
	memset(chk, 0, sizeof(chk));
}

int dijkstra(int s, int e) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (chk[node]) continue;
		chk[node] = true;


		for (int i = 0; i < n; i++) {
			int next_cost = mat[node][i];
			if (next_cost == INF) continue;
			if (chk[i]) continue;

			if (dist[i] >= d + next_cost) {
				dist[i] = d + next_cost;
				from[i].push_back(node);
				pq.push({ -dist[i], i });
			}
		}
	}
	if (dist[e] == INF)
		return -1;
	else
		return dist[e];
}

void remove(int t) {
	queue<int> q;
	q.push(t);
	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (auto x : from[p]) {
			if (mat[x][p] != INF && dist[p] == dist[x] + mat[x][p]) {
				mat[x][p] = INF;
				q.push(x);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		int start, end;
		cin >> start >> end;

		init(true);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			mat[a][b] = c;
		}

		int least = dijkstra(start, end);
		if (least == -1) {
			cout << -1 << endl;
			continue;
		}
		remove(end);
		init(false);
		int ans = dijkstra(start, end);
		cout << ans << endl;
	}
}