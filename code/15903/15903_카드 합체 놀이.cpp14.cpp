#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<long long> q;
int card[1001];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		q.push(-t);
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		long long tmp1 = -q.top();
		q.pop();
		long long tmp2 = -q.top();
		q.pop();
		long long tmp = tmp1 + tmp2;
		q.push(-tmp);
		q.push(-tmp);
	}
	while (!q.empty()) {
		ans += (-q.top());
		q.pop();
	}
	cout << ans << '\n';

}