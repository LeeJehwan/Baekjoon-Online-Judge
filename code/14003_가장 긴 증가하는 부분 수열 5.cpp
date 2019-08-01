#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
int a[1000005];
int dp[1000005];
vector<ii> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];


	int idx = 0;
	v.push_back({ 0, a[0] });
	for (int i = 1; i < n; i++) {
		if (dp[idx] < a[i]) {
			dp[++idx] = a[i];
			v.push_back({ idx, a[i] });
		}
		else {
			auto it = lower_bound(dp, dp + idx, a[i]);
			dp[it - dp] = a[i];
			v.push_back({ it - dp, a[i] });
		}
	}
	cout << idx + 1 << endl;

	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i].first == idx) {
			s.push(v[i].second);
			idx--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}
