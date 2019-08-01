#include <iostream>
using namespace std;

int a[500001];
int t[500001];
long long ans;
void merge(int s, int m, int e) {
	int p1 = s, p2 = m;
	int idx = 0;
	while (p1 < m && p2 < e) {
		if (a[p1] > a[p2]) {
			t[idx++] = a[p2++];
			ans += m - p1;
		}
		else {
			t[idx++] = a[p1++];
		}
	}
	while (p1 < m) {
		t[idx++] = a[p1++];
	}
	while (p2 < e) {
		t[idx++] = a[p2++];
	}
	for (int i = 0; i < e - s; i++) {
		a[s + i] = t[i];
	}
}

void solve(int s, int e) {
	int mid = (s + e) / 2;
	if (s < mid) {
		solve(s, mid);
		solve(mid, e);
		merge(s, mid, e);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	solve(0, n);
	cout << ans << endl;
}