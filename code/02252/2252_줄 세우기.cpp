#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

vector<int> v[32001];
int s[32001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		s[b] += 1;
	}

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; i++) {
		pq.push({ -s[i], i });
	}

	for (int i = 0; i < n; i++) {
		auto t = pq.top();
		pq.pop();
		cout << t.second << " ";

		for (auto x : v[t.second]) {
			s[x] -= 1;
			pq.push({ -s[x], x });
		}
	}
	cout << endl;
}