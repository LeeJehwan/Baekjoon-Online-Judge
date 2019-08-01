#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int dp[1000005];
int a[1000005];
typedef pair<int, int> pi;
vector<pi> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int idx = 0;
	dp[0] = a[0];
	v.push_back({ 0, dp[0] });
	for (int i = 1; i < n; i++) {
		if (dp[idx] < a[i]) {
			dp[++idx] = a[i];
			v.push_back({ idx, a[i] });
		}
		else {
			auto ii = lower_bound(dp, dp + idx, a[i]);
			dp[ii - dp] = a[i];
			v.push_back({ ii - dp, a[i] });
		}
	}
	cout << idx + 1 << endl;
	int ret = idx;
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		if (ret == v[i].first) {
			ret--;
			s.push(v[i].second);
		}
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}