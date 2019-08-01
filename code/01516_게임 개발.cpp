#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'

int time[501];
vector<int> v[501];
int in[501];
int ans[501];
vector<int> tmp[501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vector<int> tmp_v;
		int t;
		while (1) {
			cin >> t;
			if (t == -1) break;
			tmp_v.push_back(t);
		}
		time[i] = tmp_v[0];
		for (int j = 1; j < tmp_v.size(); j++) {
			v[tmp_v[j]].push_back(i);
			in[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) {
			ans[i] = time[i];
			q.push(i);
		}

	while (!q.empty()) {
		int p = q.front();
		q.pop();

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

	for (int i = 1; i <= n; i++) {
		cout << time[i] << endl;
	}

}