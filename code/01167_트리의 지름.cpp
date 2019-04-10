#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define endl '\n'

vector<pair<int, int>> v[100001];
bool chk[100001];
int max1 = 0;
int maxU = 0;
void dfs(int x, int dist) {
	if (max1 < dist) {
		max1 = dist;
		maxU = x;
	}
	chk[x] = true;
	int len = v[x].size();
	for (int i = 0; i < len; i++) {
		int y = v[x][i].first;
		if (!chk[y]) {
			dfs(y, dist + v[x][i].second);
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int node;
		cin >> node;

		while (1) {
			int x, y;
			cin >> x;
			if (x == -1)
				break;
			cin >> y;
			v[node].push_back({ x,y });
			v[x].push_back({ node,y });
		}
	}

	dfs(1, 0);
	int u = maxU;
	maxU = 0;
	max1 = 0;
	memset(chk, 0, sizeof(chk));
	dfs(u, 0);

	cout << max1 << endl;
}