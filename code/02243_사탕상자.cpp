#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000005
#define INF 1e9+10
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pi;
ll tree[MAX * 4];

void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = 0;
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int rank) {
	int mid = (start + end) / 2;
	if (start == end) {
		return start;
	}
	if (tree[node * 2] < rank) {
		return query(node * 2 + 1, mid + 1, end, rank - tree[node * 2]);
	}
	if (tree[node] >= rank) {
		return query(node * 2, start, mid, rank);
	}
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || end < idx)
		return;
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	init(1, 1, 1000000);
	while (n--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			int t = query(1, 1, 1000000, b);
			update(1, 1, 1000000, t, -1);
			cout << t << endl;
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			update(1, 1, 1000000, b, c);
		}
	}

}