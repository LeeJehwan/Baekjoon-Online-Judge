#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int l = 0, r = 0;
	int ans = 100001;
	long long sum = 0;
	while (1) {
		if (sum < s) {
			sum += a[r++];
		}
		else if (sum >= s) {
			ans = min(ans, r - l);
			sum -= a[l++];
		}
		if (l == n || r > n)
			break;
	}
	if (ans == 100001)
		cout << 0 << endl;
	else
		cout << ans << endl;

}