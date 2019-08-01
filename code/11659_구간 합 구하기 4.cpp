#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAX 100005

int a[MAX];
long long sum[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++) {
		int q, v;
		cin >> q >> v;
		if (q > v) swap(q, v);
		cout << sum[v] - sum[q - 1] << endl;
	}
}