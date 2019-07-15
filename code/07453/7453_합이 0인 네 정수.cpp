#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[4001], b[4001], c[4001], d[4001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	vector<int> v(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i*n + j] = a[i] + b[j];
		}
	}
	sort(v.begin(), v.end());

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = c[i] + d[j];
			auto up = upper_bound(v.begin(), v.end(), -tmp);
			auto lo = lower_bound(v.begin(), v.end(), -tmp);
			ans += up - lo;
		}
	}

	cout << ans << endl;

}