#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

vector<int> v[10001];
vector<int> level[10001];
vector<int> p[10001];

int cnt = 1;
int max_lev = 0;
void preorder(int x, int lev) {
	max_lev = max(lev, max_lev);
	v[x].push_back(lev);
	if (v[x][0] != -1) preorder(v[x][0], lev + 1);
	if (v[x][1] != -1) preorder(v[x][1], lev + 1);
}

void inorder(int x) {
	if (v[x][0] != -1) inorder(v[x][0]);
	level[v[x][2]].push_back(cnt++);
	if (v[x][1] != -1) inorder(v[x][1]);
}

int dfs(int x) {
	if (p[x].size() == 0)
		return x;
	dfs(p[x][0]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int node, left, right;
		cin >> node >> left >> right;
		p[left].push_back(node);
		p[right].push_back(node);
		v[node].push_back(left);
		v[node].push_back(right);
	}
	
	int root = dfs(1);
	preorder(root,1);
	inorder(root);
	int ans = 0;
	int ans_lev = 1;
	for (int i = 1; i <= max_lev; i++) {
		sort(level[i].begin(), level[i].end());
		int tmp = level[i][level[i].size() - 1] - level[i][0];
		if (tmp > ans) {
			ans = tmp;
			ans_lev = i;
		}
	}
	cout << ans_lev << " " << ans + 1 << endl;
}