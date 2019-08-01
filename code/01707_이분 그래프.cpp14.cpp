#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v[20001];
int check[20001];
bool ans = 1;
void dfs(int x, int c) {
	int len = v[x].size();
	check[x] = 3 - c;
	for (int i = 0; i < len; i++) {
		int y = v[x][i];
		if (check[y] == check[x])
			ans = 0;
		if (check[y] == false) {
			dfs(y, check[x]);
		}
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, e;
		cin >> n >> e;

		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);
		}
		for (int i = 1; i <= n; i++) {
			if(check[i]==false)
				dfs(i, 1);
		}

		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		for (int i = 1; i <= n; i++)
			v[i].clear();
		memset(check, 0, sizeof(check));
		ans = 1;
	}
}


