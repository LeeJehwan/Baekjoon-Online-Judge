#include <iostream>
#include <vector>
using namespace std;

vector <int> ve[2001];
bool chk[2001];
int ans;
int dfs(int start, int count) {
	if (count == 5)
		return ans = 1;
	int len = ve[start].size();
	chk[start] = true;
	for (int i = 0; i < len; i++) {
		if(!chk[ve[start][i]])
			dfs(ve[start][i], count + 1);
		if (ans)
			return 1;
	}
	chk[start] = false;
	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		int ans = dfs(i, 1);
		if (ans) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;

}