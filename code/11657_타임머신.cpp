#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define INF 1e9

struct Edge {
	int from, to, cost;
};
int dist[501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<Edge> v(m);
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;

	for (int i = 0; i < m; i++) {
		cin >> v[i].from >> v[i].to >> v[i].cost;
	}

	for (int i = 1; i <= n; i++) {
		for (auto x : v) {
			if (dist[x.from] != INF && dist[x.to] > dist[x.from] + x.cost) {
				dist[x.to] = dist[x.from] + x.cost;
				if (n == i) {
					cout << -1 << endl;
					return  0;
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF)
			cout << -1 << endl;
		else
			cout << dist[i] << endl;
	}

}