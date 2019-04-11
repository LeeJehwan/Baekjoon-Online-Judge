#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'

vector<int> tree[10005];
vector<int> height[10005];
vector<int> v[10005];
int cnt = 1;
int max_h = 0;
void inorder(int n, int h) {
	if (n == -1)
		return;
	if (h > max_h)
		max_h = h;
	inorder(tree[n][0], h + 1);
	height[h].push_back(cnt++);
	inorder(tree[n][1], h + 1);
}

int dfs(int s) {
	if (v[s].size() == 0)
		return s;

	dfs(v[s][0]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int node, left, right;
		cin >> node >> left >> right;
		tree[node].push_back(left);
		tree[node].push_back(right);
		if (left != -1)
			v[left].push_back(node);
		if (right != -1)
			v[right].push_back(node);
	}
	int root = dfs(1);

	inorder(root, 1);
	int max = -1;
	int good = 0;
	for (int i = 1; i <= max_h; i++) {
		int len = height[i].size();
		int tmp;
		if (len == 1)
			tmp = 1;
		else
			tmp = height[i][len - 1] - height[i][0] + 1;

		if (tmp > max) {
			max = tmp;
			good = i;
		}
	}

	cout << good << " " << max << endl;

}