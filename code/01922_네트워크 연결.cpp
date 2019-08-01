#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'

struct Edge {
	int cost;
	int u;
	int v;
};

int p[1005];
int n, m;
void init() {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
}

int find(int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = find(p[x]);
}

void _union(int x, int y) {
	int r1 = find(x);
	int r2 = find(y);
	if (r1 != r2)
		p[r1] = r2;
}

bool cmp(Edge e1, Edge e2) {
	return e1.cost < e2.cost;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> m;

	vector<Edge> e;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		Edge eg;
		eg.u = a; eg.v = b; eg.cost = cost;
		e.push_back(eg);
	}
	init();
	sort(e.begin(), e.end(), cmp);
	int ans = 0;
	for (auto x : e) {
		int r1 = find(x.u);
		int r2 = find(x.v);
		if (r1 != r2) {
			_union(r1, r2);
			ans += x.cost;
		}
	}
	cout << ans << endl;
}