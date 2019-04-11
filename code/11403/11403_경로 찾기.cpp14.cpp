#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
vector<int> v[101];
int ans[101][101];

void dfs(int s, int x) {
	ans[s][x] = 1;
	int len = v[x].size();
	for (int i = 0; i < len; i++) {
		if (ans[s][v[x][i]] == 0)
			dfs(s, v[x][i]);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (t == 1)
				v[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++) {
		int len = v[i].size();
		for (int j = 0; j < len; j++) {
			dfs(i, v[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}