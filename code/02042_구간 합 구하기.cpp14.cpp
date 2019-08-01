#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl '\n'

void init(vector<long long> &tree, vector<long long> &a, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		init(tree, a, node * 2, start, (start + end) / 2);
		init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(vector<long long> &tree, int node, int start, int end, int index, int value) {
	if (index < start || end < index)
		return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(vector<long long> &tree, int node, int start, int end, int i, int j) {
	if (j < start || end < i)
		return -1;
	if (start >= i && j >= end) {
		return tree[node];
	}
	long long m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	long long m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return m1 + m2;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);
	init(tree, a, 1, 0, n - 1);

	int q = m + k;
	while (q--) {
		int mode, start, end;
		cin >> mode >> start >> end;
		if (mode == 1)
			update(tree, 1, 0, n - 1, start - 1, end);
		else
			cout << query(tree, 1, 0, n - 1, start - 1, end - 1) << endl;
	}

}