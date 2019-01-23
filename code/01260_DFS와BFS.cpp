#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<int> v[1001];
bool chk[1001];
void dfs(int x) {
	cout << x << ' ';
	chk[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		if (!chk[v[x][i]]) {
			dfs(v[x][i]);
		}
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	chk[x] = true;
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		cout << y << ' ';

		for (int i = 0; i < v[y].size(); i++) {
			if (!chk[v[y][i]]) {
				q.push(v[y][i]);
				chk[v[y][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(start);
	cout << endl;
	memset(chk, 0, sizeof(chk));
	bfs(start);
	cout << endl;
}