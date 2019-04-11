#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
#define endl '\n'

int chk[3001];

bool is_connected(tuple<int,int,int> &t1, tuple<int,int,int> &t2) {
	int x1, x2, y1, y2, r1, r2;
	tie(x1, y1, r1) = t1;
	tie(x2, y2, r2) = t2;
	int r = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	if (r <= (r1 + r2)*(r1 + r2))
		return true;
	else
		return false;
}


void solve() {
	vector<int> node[3001];
	memset(chk, 0, sizeof(chk));
	int n;
	cin >> n;

	vector<tuple<int, int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		v.push_back({ x,y,r });
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (is_connected(v[i], v[j])) {
				node[i].push_back(j);
				node[j].push_back(i);
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (chk[i]) continue;

		queue<int> q;
		q.push(i);
		chk[i] = 1;
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int k = 0; k < node[x].size(); k++) {
				int y = node[x][k];
				if (chk[y]) continue;

				q.push(y);
				chk[y] = 1;
			}
		}
		ans++;
	}
	cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}