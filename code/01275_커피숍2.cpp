#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
int a[100001];
long long tree[100001 * 4];

void init(int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (idx < start || idx > end) {
		return;
	}
	if (start == end) {
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


long long query(int node, int left, int right, int q_start, int q_end) {
	//1. query 구간이 node 포함
	if (q_start <= left && right <= q_end) {
		return tree[node];
	}
	//2. node 구간과 query 겹치지 않을 때
	if (q_end < left || right < q_start) {
		return 0;
	}
	//3. 조금 겹치거나 포함되거나
	int mid = (left + right) / 2;
	long long m1 = query(node * 2, left, mid, q_start, q_end);
	long long m2 = query(node * 2 + 1, mid + 1, right, q_start, q_end);
	return m1 + m2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	init(1, 0, n - 1);
	while (q--) {
		int x, y, s, e;
		cin >> x >> y >> s >> e;
		if (x > y)
			swap(x, y);
		cout << query(1, 0, n - 1, x - 1, y - 1) << endl;
		update(1, 0, n - 1, s - 1, e);

	}
}