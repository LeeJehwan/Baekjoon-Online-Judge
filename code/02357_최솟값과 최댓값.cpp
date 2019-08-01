#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100005
#define INF 1e9+10
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pi;
pi tree[MAX * 4];
int arr[MAX];

void init(int node, int start, int end) {
	if (start == end) {
		tree[node].first = arr[start];
		tree[node].second = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
	tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
}

pi query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return{ INF, -1 };
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	pi m1 = query(node * 2, start, mid, left, right);
	pi m2 = query(node * 2 + 1, mid + 1, end, left, right);
	return{ min(m1.first, m2.first), max(m1.second, m2.second) };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pi tmp = query(1, 1, n, a, b);
		cout << tmp.first << ' ' << tmp.second << endl;
	}

}