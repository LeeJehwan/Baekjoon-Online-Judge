#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl '\n'

void init(vector<int> &tree, vector<int> &a, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(vector<int> &tree, int node, int start, int end, int i, int j) {
	if (end < i || start > j)
		return -1;
	if (i <= start && end <= j)
		return tree[node];
	int m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	int m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return min(m1, m2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int h = (int)ceil(log2(n));
	int tree_size = (1 << h + 1);
	vector<int> tree(tree_size);
	init(tree, a, 1, 0, n - 1);
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << query(tree, 1, 0, n - 1, s - 1, e - 1) << endl;
	}


}