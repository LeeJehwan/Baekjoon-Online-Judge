#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define endl '\n'

vector<pair<int,int>> v[20001];
int d[20001];
bool chk[20001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int start;
	cin >> start;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b, w });
	}
	for (int i = 1; i <= n; i++) {
		d[i] = INT_MAX;
	}
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({ 0, start });
	d[start] = 0;
	while (!q.empty()) {
		int wt = q.top().first;		
		int dst = q.top().second;		
		q.pop();

		if (chk[dst]) continue;
		chk[dst] = true;

		for (int i = 0; i < v[dst].size(); i++) {
			int t1 = v[dst][i].first;	
			int t2 = v[dst][i].second;	

			if (wt + t2 < d[t1]) {
				d[t1] = wt + t2;
				q.push({ d[t1], t1 });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == INT_MAX)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
}