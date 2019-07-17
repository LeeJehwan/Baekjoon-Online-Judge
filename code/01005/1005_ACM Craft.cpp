#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl '\n'

int time[1001];
vector<int> v[1001];
int in[1001];
int ans[1001];
vector<int> tmp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			in[b]++;
		}
		int fin;
		cin >> fin;

		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (in[i] == 0) {
				ans[i] = time[i];
				q.push(i);
			}

		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (p == fin) break;

			for (auto x : v[p]) {
				in[x]--;

				tmp[x].push_back(time[p]);

				if (in[x] == 0) {
					sort(tmp[x].begin(), tmp[x].end());
					time[x] += tmp[x][tmp[x].size() - 1];
					q.push(x);
				}
			}
		}

		cout << time[fin] << endl;

		memset(time, 0, sizeof(time));
		memset(in, 0, sizeof(in));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i <= n; i++) {
			v[i].clear();
			tmp[i].clear();
		}

	}
}