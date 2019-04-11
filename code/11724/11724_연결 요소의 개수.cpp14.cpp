#include <iostream>
#include <vector>
using namespace std;

vector<int> vertex[1001];
bool check[1001];
bool control = 0;
void dfs(int x) {
	int len = vertex[x].size();
	if (!check[x]) {
		control = true;
		check[x] = true;
	}

	for (int i = 0; i < len; i++) {
		int y = vertex[x][i];
		if (check[y] == false)
			dfs(y);
	}
}



int main() {
	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;

		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		dfs(i);
		if (control) {
			cnt++;
			control = false;
		}
	}
	cout << cnt << endl;
}