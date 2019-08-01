#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'

int chk[501];
vector<int> v[501];
int main() {
	int n, m;
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}

	queue<int> q;
	q.push(1);
	chk[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!chk[y]) {
				chk[y] = chk[x] + 1;
				q.push(y);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (chk[i] == 2 || chk[i] == 3)
			cnt++;
	}
	cout << cnt << endl;

}